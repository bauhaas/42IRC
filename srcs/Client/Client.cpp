#include "../../includes/client.hpp"

/*
** Constructeur
** TODO: voir ce qu'il y a de mieux pour initialiser les valeurs
** Attention particuliere a porter sur le nickname et le password (?)
*/
Client::Client(void): _nickname("null"), _username("null"), _hostname("null"), _realname("null"), _modes("null"), _has_operator_status(false), _is_away(false), _away_mssg("null"), _password("null"), _fd(0), _message_status(0), _message("null"), _server_name("null"), _server_ip("null"), _server_creation("null"), _channels(NULL), _commands(NULL), _port("null"), _user_is_oper(0), _user_is_away(0), _user_has_registered_pass(0), _user_has_registered_nick(0), _user_is_registered(0)
{
#if DEBUG
	std::cout << "Client default constructor called" << std::endl;
#endif
	return ;
}

/*
** Faire des tests pour voir ce qui est important pour l'initialisation
*/
Client::Client(std::string server_name, std::string server_ip, std::string server_creation, std::string port): _nickname("null"), _username("null"), _hostname("null"), _realname("null"), _modes("null"), _has_operator_status(false), _is_away(false), _away_mssg("null"), _password("null"), _fd(0), _message_status(0), _message("null"), _server_name(server_name), _server_ip(server_ip), _server_creation(server_creation), _channels(NULL), _commands(NULL), _port(port), _user_is_oper(0), _user_is_away(0), _user_has_registered_pass(0), _user_has_registered_nick(0), _user_is_registered(0)
{
#if DEBUG
	std::cout << "Client default constructor called" << std::endl;
#endif
	return ;
}

/*
** Destructeur
*/
Client::~Client(void)
{
#if DEBUG
	std::cout << "Client destructor called" << std::endl;
#endif
    return;
}

/*
** Setters
*/

void						Client::set_nickname(std::string nickname)
{
	this->_nickname = nickname;
#if DEBUG
	std::cout << "Client's nickname has been set to " << nickname << std::endl;
#endif
	return ;
}

void 						Client::set_username(std::string username)
{
	this->_username = username;
#if DEBUG
	std::cout << "Client's username has been set to " << username << std::endl;
#endif
}

void						Client::set_realname(std::string realname)
{
	this->_realname = realname;
#if DEBUG
	std::cout << "Client's realname has been set to " << realname << std::endl;
#endif
}

void						Client::set_hostname(std::string hostname)
{
	this->_hostname = hostname;
#if DEBUG
	std::cout << "Client's hostname has been set to " << hostname << std::endl;
#endif
}

void						Client::set_modes(std::string modes)
{
	this->_modes = modes;
#if DEBUG
	std::cout << "Client's modes has been set to " << modes << std::endl;
#endif
}

void						Client::set_operator_status(bool value)
{
	this->_has_operator_status = value;
#if DEBUG
	std::cout << "Client's operator status has been set to " << value << std::endl;
#endif
}

void 						Client::set_is_away(bool value)
{
	this->_is_away = value;
#if DEBUG
	std::cout << "Client's is away status has been set to " << value << std::endl;
#endif
}

void						Client::set_away_mssg(std::string message)
{
	this->_away_mssg = message;
#if DEBUG
	std::cout << "Client's is away message has been set to " << message << std::endl;
#endif
}

/*
** Setters added
*/
void						Client::set_password_as_registered(bool is_set)
{
	this->_pass_registered = is_set;
#if DEBUG
	std::cout << "password registered is " << is_set << std::endl;
#endif
}

void						Client::set_registered_nickname(bool is_set)
{
	this->_nick_registered= is_set;
#if DEBUG
	std::cout << "nickname registered is " << is_set << std::endl;
#endif
}

void						Client::set_registered_user(bool is_set)
{
	this->_user_is_registered = is_set;
#if DEBUG
	std::cout << "user is registered ? " << is_set << std::endl;
#endif
}

void						Client::set_registered_user(bool is_set)
{
	this->_user_is_registered = is_set;
#if DEBUG
	std::cout << "user is registered ? " << is_set << std::endl;
#endif
}

void						Client::set_operator(bool is_set)
{
	this->_has_operator_status = is_set;
#if DEBUG
	std::cout << "user is operator ? " << is_set << std::endl;
#endif
}

int							Client::set_message_status(int status)
{
	this->_message_status = status;
#if DEBUG
	std::cout << "Client Operator status " << status << std::endl;
#endif
}

/*
** revoir si on prefere utiliser select ou socket
*/
void						Client::set_init_socket(int socket)
{
	this->_socket = socket;
	//this->fd = socket;
#if DEBUG
	std::cout << "Client socket is " << socket << std::endl;
#endif
}

/*
** Rechercher dans la documentation
*/
void						Client::set_server_name(std::string server_name)
{
	this->_server_name = server_name;
#if DEBUG
	std::cout << "Server name has been set to " << server_name << std::endl;
#endif
}

/*
** Verifier si il ne vaudrait pas mieux que ce soit const
*/
void						Client::set_server_ip(std::string server_ip)
{
	this->_server_ip = server_ip;
#if DEBUG
	std::cout << "Server ip has been set to " << server_ip << std::endl;
#endif
}

void						Client::set_server_creation(std::string creation)
{
	this->_server_creation = creation;
#if DEBUG
	std::cout << "Server creation has been set to " << creation << std::endl;
#endif
}

/*
** Getters
*/
std::string					Client::get_nickname(void) const
{
	std::string nick = this->_nickname;
#if DEBUG
	std::cout << "Client's nickname is " << nick << std::endl;
#endif
	return (nick);
}

std::string					Client::get_username(void) const
{
	std::string user = this->_username;
#if DEBUG
	std::cout << "Client's username is " << user << std::endl;
#endif
	return (user);
}

std::string					Client::get_realname(void) const
{
	std::string	real = this->_realname;
#if DEBUG
	std::cout << "Client's realname is " << real << std::endl;
#endif
	return (real);
}

std::string					Client::get_hostname(void) const
{
	std::string host = this->_hostname;
#if DEBUG
	std::cout << "Client's hostname is " << host << std::endl;
#endif
	return (host);
}

std::string					Client::get_modes(void) const
{
	std::string modes;
	modes = this->_modes;
#if DEBUG
	std::cout << "Client's modes is " << modes << std::endl;
#endif
	return (modes);
}

bool						Client::get_operator_status(void) const
{
	bool op = this->_has_operator_status;
#if DEBUG
	std::cout << "Client's operator status is " << op << std::endl;
#endif
	return (op);
}

bool 						Client::get_is_away(void) const
{
	bool op = this->_is_away;
#if DEBUG
	std::cout << "Client's away status is " << op << std::endl;
#endif
	return (op);
}

std::string					Client::get_away_mssg(void) const
{
	std::string away = this->_away_mssg;
#if DEBUG
	std::cout << "Client's away message is " << away << std::endl;
#endif
	return (away);
}

/*
** Added
*/
std::string					Client::get_password(void) const
{
	std::string pass = this->_password;
#if DEBUG
	std::cout << "Client's away message is " << away << std::endl;
#endif
	return (pass);
}

/*
** Checker les valeurs du fd ?
*/
int							Client::get_fd(void) const
{
	int fd = this->_fd;
#if DEBUG
	std::cout << "Client's fd is " << fd << std::endl;
#endif
	return (fd);
}

std::string					Client::get_server_port(void) const
{
	std::string port = this->_port;
#if DEBUG
	std::cout << "Client's port is " << port << std::endl;
#endif
	return (port);
}

std::string					Client::get_message(void) const
{
	std::string message = this->_message;
#if DEBUG
	std::cout << "Client's message is " << message << std::endl;
#endif
	return (message);
}

/*
** voir message status
*/
int							Client::get_message_status(void) const
{
	int status = this->_message_status;
#if DEBUG
	std::cout << "Client's message_status is " << status << std::endl;
#endif
	return (status);
}

/*
** Voir quand la socket est necessaire
*/
int							Client::get_socket(void) const
{
	int socket = this->_socket;
#if DEBUG
	std::cout << "Client's socket is " << socket << std::endl;
#endif
	return (socket);
}

/*
** Puisqu'il s'agit d'un vecteur il est aisé de retrouver sa taille
** A tester
*/
int							Client::get_channels_nb(void) const
{
	int size = this->_channels.size();
#if DEBUG
	std::cout << "This client is in " << size << " channels" << std::endl;
#endif
	return (size);
}

/*
** Utils
*/

/*
** Voir quand est-ce qu'on va le set a true
*/
bool						Client::user_is_registered(void) const
{
	bool registered = this->_registration_status;
#if DEBUG
	std::cout << "The client is registered ? " << registered << std::endl;
#endif
	return (registered);
}

/*
** Voir si c est possible que ce ne soit pas le cas ?
*/
bool						Client::user_registered_password(void) const
{
	bool password = this->_pass_registered;
#if DEBUG
	std::cout << "The client password is registered ? " << password << std::endl;
#endif
	return (password);
}

bool						Client::user_registered_nickname(void) const
{
	bool nick = this->_nick_registered;
#if DEBUG
	std::cout << "The client nick is registered ? " << nick << std::endl;
#endif
	return (nick);
}

bool						Client::user_is_away(void) const
{
	bool away = this->_user_is_away;
#if DEBUG
	std::cout << "The client is away ? " << away << std::endl;
#endif
	return (away);
}

bool						Client::user_is_operator(void) const
{
	bool ope = this->_user_is_oper;
#if DEBUG
	std::cout << "The client is operator ? " << away << std::endl;
#endif
	return (ope);
}

/*
** Voir comment gerer cette liste
*/
std::vector<std::string>	Client::user_commands(void) const
{
	std::vector<std::string> list_cmd = this->_commands;
//TODO: faire fonction d'affichage
	return (list_cmd);
}

/*
** Info server
*/
std::string					Client::get_server_name(void) const
{
	std::string name = this->_server_name;
#if DEBUG
	std::cout << "The server name is " << name << std::endl;
#endif
	return (name);
}

std::string					Client::get_server_ip(void) const
{
	std::string ip = this->_server_ip;
#if DEBUG
	std::cout << "The server ip is " << ip << std::endl;
#endif
	return (ip);
}

std::string					Client::get_server_creation(void) const
{
	std::string creation = this->_server_creation;
#if DEBUG
	std::cout << "The server creation date is " << creation << std::endl;
#endif
	return (creation);
}

/*
** Other utils
*/

/*
** Comme il s'agit d'un vecteur il est simple de tout effacer
** voir dans quel cas de figure on a besoin de clear (a part free de tout ?)
*/
void						Client::clear_client_message(void)
{
	this->_message.clear();
#if DEBUG
	std::cout << "Client message vector has been cleared." << std::endl;
#endif
}

void						Client::clear_client_command(void)
{
	this->_commands.clear();
#if DEBUG
	std::cout << "Client commands vector has been cleared." << std::endl;
#endif
}

/**
** recv (a voir)
** TODO: Damien
*/
void						Client::send_message_to_server(void)
{
	//recv
	//declarer un buffer
	//faire un memset sur le buffer
	//verifier le status du message (must be complete)
	//executer recv
	//afficher une erreur si le recv retourne une erreur
	//se deconnecter si le retour est 0
	//gerer le message s'il est incomplet
}

/**
** TODO: Damien
*/
void						Client::check_message(void)
{
	//parsing du "end char"
	//ajouter le message dans le vecteur des commandes si on a recu un end_char
}

/*
** Va permettre d'ajouter une channel au vector
** A tester
** voir s'il faudrait faire un operateur de comparaison dans channel ?
*/
void 						Client::join_channel(Channel *channel)
{
	if (!channel)
		return ;
	std::vector<Channel *>::iterator it = this->_channels.begin();
	std::vector<Channel *>::iterator ite = this->_channels.end();

	//On verifie que la channel n'existe pas deja
	while (it != ite)
	{
		if ((*it) == channel)
			return ;
		it++;

	}
	this->_channels.push_back(channel);
#if DEBUG
	std::cout << "Channel was successfully added." << std::endl;
#endif
	return ;
}

/**
** TODO: faire un overload pour operator<< sur channel
*/
void						Client::quit_channel(Channel *channel)
{
	if (!channel)
		return ;
	//on verifie si on trouve la channel
	std::vector<Channel *>::iterator it = _channels.begin();
	std::vector<Channel *>::iterator ite = _channels.end();
	while (it != ite)
	{
		if ((*it) == channel)
		{
			this->_channels.erase(it);
#if DEBUG
			std::cout << "channel was successfully deleted" << std::endl;
#endif
			return ;
		}
		it++;
	}
#if DEBUG
	std::cout << "Channel could not be erased because it was not found" << std::endl;
#endif
}

/**
** TODO: verifier que tout est ok niveau leaks etc
*/
void						Client::quit_all_channels(void)
{
	//verifier si la liste n est pas deja vide ?
	//ajouter des fonctions qui checkent si les vector sont vides ?
	this->_channels.clear();
}

/*
** Display / Debug
*/
void						Client::displayClientInfo(void)
{
	std::cout << "----- Displaying Client Info -----" << std::endl;
	std::cout << "Nickname : " << this->get_nickname() << std::endl;
	std::cout << "Username : " << this->get_username() << std::endl;
	this->displayChannels();
}

void						Client::displayChannels(void)
{
	std::cout << "--- Listing Channels ---" << std::endl;
	std::vector<Channel *>::iterator it = this->_channels.begin();
	std::vector<Channel *>::iterator ite = this->_channels.end();
	while (it != ite)
	{
		(*it)->displayChannelInfo();
		it++;
	}
	std::cout << "------------------------" << std::endl;
}

/**
 * @brief
 * TODO: faire un overload << (juste nickname ?)
 * voir si autres overload peuvent etre interessants
 */