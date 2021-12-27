#include "../IRC.hpp"

// Return a string rep of n zero-padded whose final length is width
static string	toStrZeroPadded(unsigned int n, int width)
{
	char	buf[16];
	sprintf(buf, "%0*u", width, n);
	string	res(buf);
	return res;
}

// Return a response from a valid code
string	IRC::getResponseFromCode(User *user, int code, string params[]) const
{
	stringstream	ss;
	ss	<<	_prefix
		<< " " << toStrZeroPadded(code, 3)
		<< " " << user->_nick << " ";

	switch (code)
	{
		case RPL_WELCOME:
			ss << ":Welcome to the FT_IRC Network " << params[0]; break;
		case RPL_YOURHOST:
			ss << ":Your host is " << IRC_HOST << ", running version " << IRC_VER; break;
		case RPL_CREATED:
			ss << ":This server was created " << ctime(&_startupTime);
			ss.seekp(-1, std::ios_base::end); break;
		case RPL_MYINFO:
			ss << IRC_HOST << ' ' << IRC_VER << ' ' << "biklmnopstv :" << CHAN_MODES; break;
		
		case RPL_ADMINME:
			ss << IRC_HOST << " :Administrative info"; break;
		case RPL_ADMINLOC1:
			ss << ":Name: " << params[0]; break;
		case RPL_ADMINLOC2:
			ss << ":Location: " << params[0]; break;
		case RPL_ADMINEMAIL:
			ss << ":Email: " << params[0]; break;
		
		case RPL_NOTOPIC:
			ss << params[0] << " :No topic is set" ; break;
		case RPL_TOPIC:
			ss << params[0] << " :" << params[1]; break;
		case RPL_VERSION:
			ss << IRC_VER << ". " << IRC_HOST << " :"; break;
		case RPL_NAMREPLY:
			ss << params[0] << " :" << params[1]; break;
		case RPL_ENDOFNAMES:
			ss << params[0] << " :End of /NAMES list."; break;
		case RPL_MOTDSTART:
			ss << _prefix << " message of the day"; break;
		case RPL_MOTD:
			ss << ": " << params[0]; break;
		case RPL_ENDOFMOTD:
			ss << ":End of message of the day."; break;
		case RPL_TIME:
			ss << IRC_HOST << " :" << params[0]; break;
		
		case ERR_NOSUCHNICK:
			ss << params[0] << " :No such nick"; break;
		case ERR_NOSUCHCHANNEL:
			ss << params[0] << " :No such channel"; break;
		case ERR_UNKNOWNCOMMAND:
			ss << params[0] << " :Unknown command"; break;
		case ERR_NOMOTD:
			ss << ":MOTD File is missing"; break;
		case ERR_NONICKNAMEGIVEN:
			ss << ":No nickname given"; break;
		case ERR_ERRONEUSNICKNAME:
			ss << params[0] << " :Erroneous nickname"; break;
		case ERR_NICKNAMEINUSE:
			ss << params[0] << " :Nickname is already in use"; break;
		case ERR_NOTONCHANNEL:
			ss << params[0] << " :You're not on that channel"; break;
		case ERR_NEEDMOREPARAMS:
			ss << params[0] << " :Not enough parameters"; break;
		case ERR_ALREADYREGISTRED:
			ss << ":You may not reregister"; break;
		case ERR_BADCHANNELKEY:
			ss << params[0] << " :Cannot join channel (incorrect channel key)"; break;
		case ERR_BADCHANMASK:
			ss << params[0] << " :Invalid channel name"; break;
		case ERR_CHANOPRIVSNEEDED:
			ss << params[0] << " :You're not channel operator"; break;
		default: break;
	}

	ss	<< CMD_DELIM;
	return ss.str();
}