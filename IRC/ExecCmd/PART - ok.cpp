#include "../IRC.hpp"

void	IRC::execPART(Command const &cmd, std::vector<t_clientCmd> &responseQueue)
{
	User	*user(cmd._user);
	string	resp;

	if (cmd._params.empty())
	{
		resp = getResponseFromCode(user, ERR_NEEDMOREPARAMS, (string[]){ cmd._type });
		responseQueue.push_back(std::make_pair(user->_fd, resp));
		return;
	}
	
	string const	&chanName(cmd._params[0]);
	Channel	*chan = (_channels.find(chanName) != _channels.end())
				  ? _channels[chanName]
				  : NULL;
	if (!chan)
	{
		// Channel not found
		resp = getResponseFromCode(user, ERR_NOSUCHCHANNEL, (string[]){ chanName });
		responseQueue.push_back(std::make_pair(user->_fd, resp));
		return;
	}

	if (!chan->IsJoined(user))
	{
		// User not joined channel
		resp = getResponseFromCode(user, ERR_NOTONCHANNEL, (string[]){ chanName });
		responseQueue.push_back(std::make_pair(user->_fd, resp));
		return;
	}

	if (cmd._params.size() == 1)
		appendUserNotif(
			user,
			(string[]){ "PART", ":" + chanName, "" },
			chan->_users, responseQueue
		);
	else
		appendUserNotif(
			user,
			(string[]){ "PART", chanName, ":\"" + cmd._params[1] + "\"", "" },
			chan->_users, responseQueue
		);
}