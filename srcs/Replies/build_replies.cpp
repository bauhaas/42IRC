#include <IRC.hpp>
#include <string>

#include <string>
#include <sstream>

template <typename T>
std::string ToString(T val)
{
    std::stringstream stream;
    stream << val;
    return stream.str();
}

/**
 * @brief format the code into a valid string for the server reply (ex: int 1 --> str 001)
 *
 * @param code
 * @return std::string
 * TODO: Attention - Mahaut : voir si on peut rassembler avec ce que j ai fait (error + send_rpl)
 * TODO: j ai mis error dans utils mais send_rpl dans commande
 */
std::string format_code_str(int code)
{
    if (code < 10)
        return "00" + ToString(code);
    else if (code < 100)
        return "0" + ToString(code);
    return ToString(code);
}

//TODO: Question : est-ce qu on fait une fonction separee ou est-ce qu on la raccroche a la classe IRC ?
std::string IRC::build_reply(int code, std::vector<User *>users, std::vector<std::string> params, std::string command)
{
    //Si la commande est emptuy c'est qu'il s'agit d'un 
    (void)code;
    (void)users;
    (void)params;
    (void)command;

    std::string rpl;
    return (rpl);
}

/**
 * @brief Fonction principale qui va permettre au serveur d'envoyer les RPL, les ERR 
 * mais egalement les messages "specifiques" emanant de chaque commande.
 * TODO: Mahaut : faire un overload avec plus d'arguments puis on reprendra uniquement la partie overloadee ?
 * TODO: A mettre dans la classe serveur ?
 * @param code 
 * @param user 
 * @param params 
 * @return std::string 
 */
std::string build_reply(int code, User *user, std::vector<std::string> params)
{
    (void)code;
    (void)user;
    std::string code_str;
    std::string prefix;

    code_str = format_code_str(code);
    if (user->get_nickname().empty())
        prefix = ":" + user->get_hostname() + " " + code_str + " * ";
    else
        prefix = ":" + user->get_hostname() + " " + code_str + " " + user->get_nickname() + " ";
    switch (code)
    {
    case 1:
        return prefix + RPL_WELCOME(params[0], params[1], params[2]);
    case 2:
        return prefix + RPL_YOURHOST(params[0], "1.0");
    case 3:
        return prefix + RPL_CREATED(params[0]);
    case 4: // TODO remove hardcoded version value
        return prefix + RPL_MYINFO(params[0], "1.0", USER_VALID_MODES, CHANNEL_VALID_MODES);
    case 305:
        return prefix + RPL_UNAWAY();
    case 306:
        return prefix + RPL_NOWAWAY();
    case 351:
        return prefix + RPL_VERSION(params[0], params[1], params[2], params[3]);
    case 372:
        return prefix + RPL_MOTD(params[0]);
    case 375:
        return prefix + RPL_MOTDSTART(params[0]);
    case 376:
        return prefix + RPL_ENDOFMOTD();
    case 391:
        return prefix + RPL_TIME(params[0], params[1]);
    case 402:
        return prefix + ERR_NOSUCHSERVER(params[0]);
    case 421:
        return prefix + ERR_UNKNOWNCOMMAND(params[0]);
    case 422:
        return prefix + ERR_NOMOTD();
    case 999:
        //return (":127.0.0.1 PONG 127.0.0.1 :127.0.0.1\r\n"); À CHOISIR SI ON VEUT AVOIR LE MSSG PONG VISIBLE OU NON
        return (":127.0.0.1 PONG\r\n");
    case 332:
        return prefix + RPL_TOPIC(params[0], params[1]);
    case 998:
        return prefix + "ERROR\r\n";
    default:
        return std::string("");
    }
    return std::string("");
}