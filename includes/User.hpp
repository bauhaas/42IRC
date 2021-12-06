#pragma once

#include <irc.hpp>

class Server;
class Channel;

class User
{
    private:
       User(User const &src);
       User & operator=(User const &src);

        int                         _socket;
        std::string                 _nickname;
        std::string                 _username;
        std::string                 _hostname;
        std::string                 _realname;
        std::string                 _modes;
        bool                        _has_operator_status;
        bool                        _is_away;
        std::string                 _away_mssg;
        std::string                 _password;
        int                         _message_status;
        std::string                 _message;
        std::vector<Channel *>      _channels;

        std::string                 _server_name;
        std::string                 _server_ip;
        std::string                 _server_creation;

        std::string _unparsed_client_command;
	    std::string _prefix;
	    std::string _command_name;
	    std::vector<std::string> _params;

        //voir l'importance du registration status
        bool                        _registration_status;
        bool                        _pass_registered;
        bool                        _nick_registered;
        std::string                 _port;
        bool                        _user_is_oper;
        bool                        _user_is_away;
        bool                        _user_has_registered_pass;
        bool                        _user_has_registered_nick;
        bool                        _user_is_registered;    //?
        //std::vector<std::string>  _cap;
        //std::vector<std::string>  _nick;
        //std::vector<std::string>  _user;

    public:
        Server                      *_server;

        //voir si constructeur par defaut a mettre en prive
        User(void);
        User(std::string server_name, std::string server_ip, std::string server_creation, std::string port);
        virtual ~User();

        std::string                 get_nickname(void) const;
        std::string                 get_username(void) const;
        std::string                 get_realname(void) const;
        std::string                 get_hostname(void) const;
        std::string                 get_modes(void) const;
        bool                        get_operator_status(void) const;
        bool                        get_is_away(void) const;
        std::string                 get_away_mssg(void) const;
        std::string                 get_password(void) const;
        std::string                 get_server_port(void) const;
        std::string                 get_message(void) const;
        int                         get_message_status(void) const;
        int                         get_socket(void) const;
        int                         get_channels_nb(void) const;
        std::vector<std::string>    get_params(void) const;
        std::string                 get_command_name(void) const;
        std::string                 get_prefix(void) const;

        bool                        user_is_registered(void) const;
        bool                        user_registered_password(void) const;
        bool                        user_registered_nickname(void) const;
        bool                        user_is_away(void) const;
        bool                        user_is_operator(void) const;
        std::vector<std::string>    user_commands(void) const;

        std::string                 get_server_name(void) const;
        std::string                 get_server_ip(void) const;
        std::string                 get_server_creation(void) const;
        Server                      *get_server(void);

        std::string                 get_unparsed_client_command(void) const;
        //a verifier
        bool                        check_if_prefix(void) const;

        void                        set_nickname(std::string nickname);
        void                        set_username(std::string username);
        void                        set_realname(std::string realname);
        void                        set_hostname(std::string hostname);
        void                        set_modes(std::string modes);
        void                        set_operator_status(bool value);
        void                        set_is_away(bool value);
        void                        set_away_mssg(std::string message);
        void set_server(Server server);
        void set_unparsed_client_command(std::string client_command);
    
        void                        set_command(std::string command);
        void                        set_password_as_registered(bool is_set);
        void                        set_registered_nickname(bool is_set);
        void                        set_registered_user(bool is_set);
        void                        set_operator(bool is_set);
        void                         set_message_status(int status);
       // void                        set_registration(bool is_set);
        void                        set_init_socket(int socket);

        void                        set_server_name(std::string server_name);
        void                        set_server_ip(std::string server_ip);
        void                        set_server_creation(std::string server_creation);

       void                         clear_client_message(void);
       void                         clear_client_command(void);
       void                         send_message_to_server(void);
       void                         check_message(void);
       void                         join_channel(Channel *channel);
       void                         quit_channel(Channel *channel);
       void                         quit_all_channels(void);

       int store_string_until_char(std::string *dest, std::string *src, char c, int len);
       void patch_params(std::vector<std::string> *params);
       void split_string_to_vector(std::vector<std::string> *vec, std::string *str, char c);
       void store_prefix(void);
       void store_command(void);
       void store_params(void);
       
      //std::vector<std::string> get_params(void);
      unsigned int get_params_size(void) const;

       void check_command(void);
       void exec_command(void);


       void                         displayClientInfo(void);
       void                         displayChannels(void);
       void                         display_command(void);
       void	                        display_params(void);
};