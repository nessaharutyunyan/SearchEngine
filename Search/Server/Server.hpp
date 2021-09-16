#ifndef SERVER_HPP
#define SERVER_HPP

#include <string>

#include <cpprest/json.h>
#include <cpprest/http_listener.h>

#include "mysql.hpp"
#include "Search/Search.hpp"

using namespace web;
using namespace web::http;
using namespace web::http::experimental::listener;

class Server
{
private:
    http_listener listener;
    Search search;
    sql::Connection* connection;

private:
    void handleGet(http_request request);

public:
    Server(std::string hostName, std::string DBhostName, std::string DBuserName, std::string DBpassword);
    Server(std::string hostName, unsigned short port, std::string DBhostName, std::string DBuserName, std::string DBpassword);
    ~Server();

};

#endif