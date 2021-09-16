#ifndef SEARCH_HPP
#define SEARCH_HPP

#include <vector>
#include "../MySQL/mysql.hpp"
#include "cpprest/json.h"

class SearchResult
{
private:
    std::string url;
    std::string title;

public:
    SearchResult(const std::string& url, const std::string& title);
    web::json::value asJSON() const;
};

class Search
{
private:

public:
    std::vector<SearchResult> search(const std::string& text, sql::Connection* connection, unsigned int count);

};

#endif