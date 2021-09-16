#include "Server.hpp"

Server::Server(std::string hostName, std::string DBhostName, std::string DBuserName, std::string DBpassword)
        : listener(hostName)
{
    sql::mysql::MySQL_Driver* driver = sql::mysql::get_driver_instance();
    connection = driver->connect(DBhostName, DBuserName, DBpassword);

    this->listener.support(methods::GET, std::bind(&Server::handleGet, this, std::placeholders::_1));
    try
    {
        std::cout << "Starting Search server..." << std::endl;
        this->listener.open();
        std::cout << "Search server started.\nWaiting for requests" << std::endl;
    }
    catch (std::exception &e)
    {
        std::cout << "Server Search didn't start" << std::endl;
        std::cout << e.what() << std::endl;
    }
}

Server::Server(std::string hostName, unsigned short port, std::string DBhostName, std::string DBuserName, std::string DBpassword)
        : listener(hostName.append(std::to_string(port)))
{
    this->listener.support(methods::GET, std::bind(&Server::handleGet, this, std::placeholders::_1));
    try
    {
        std::cout << "Starting Search server..." << std::endl;
        this->listener.open();
        std::cout << "Search server started.\nWaiting for requests" << std::endl;
    }
    catch (std::exception &e)
    {
        std::cout << "Server Search didn't start" << std::endl;
        std::cout << e.what() << std::endl;
    }
}

Server::~Server()
{
    listener.close();
}

void Server::handleGet(http_request request)
{
    auto message = request.extract_string().get();

    std::cout << message << std::endl;

    auto results = search.search(message, this->connection, 10);

    auto jvalue = json::value::object();
    auto jarray = json::value::array();

    unsigned int index = 0;

    for(auto r : results)
    {
        jarray[index++] = r.asJSON();
    }

    jvalue["results"] = jarray;

    std::cout << jvalue.serialize() << std::endl;
    request.reply(status_codes::OK, jvalue);
}