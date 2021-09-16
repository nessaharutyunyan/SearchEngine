#include <cpprest/http_listener.h>
#include <cpprest/json.h>

#include "mysql.hpp"
#include "Server.hpp"

using namespace web;
using namespace web::http;
using namespace web::http::experimental::listener;

int main()
{
    // SQL DataBase
    const sql::SQLString DBhostName = "tcp://localhost:3306/Crawler";
    const sql::SQLString DBuserName = "root";
    const sql::SQLString DBpassword = "Admin_1390";

    // Server
    const std::string serverHostName = "http://localhost:23568";

    Server server(serverHostName, DBhostName, DBuserName, DBpassword);
    while(true)
    {
        // Server Control Panel
        std::string commandLine;
        std::cin >> commandLine;

        if(commandLine == "help" || commandLine == "h")
        {
            std::cout << "Available commands: " << std::endl;
            std::cout << "exit - shutdown server" << std::endl;
        }
        else if(commandLine == "exit" || commandLine == "e")
        {
            break;
        }
        else
        {
            std::cout << "Unknown command \nType help for information" << std::endl;
        }
    }

    return 0;
}