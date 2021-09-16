#include "Search.hpp"

SearchResult::SearchResult(const std::string& url, const std::string& title) :
        url(url),
        title(title)
{
}

web::json::value SearchResult::asJSON() const
{
    web::json::value result = web::json::value::object();

    result["url"] = web::json::value::string(this->url);
    result["title"] = web::json::value::string(this->title);

    return result;
}

std::vector<SearchResult> Search::search(const std::string& text, sql::Connection* connection, unsigned int count)
{
    std::vector<SearchResult> results{};
    auto prepst = connection->prepareStatement("SELECT * from Documents WHERE MATCH(title, description, content) AGAINST ((?) in NATURAL LANGUAGE MODE)");
    std::string textSearch = "'%"+ text +"%'";
    prepst->setString(1, textSearch);
    auto result = prepst->executeQuery();
    for(unsigned int i = 0; i < count; ++i)
    {
        if(!result->next())
        {
            break;
        }
        std::cout << "Search::search " << result->getString("title") << " " << result->getString("url") << "\n";
        std::string url = result->getString("url").asStdString();
        std::string title = result->getString("title").asStdString();
        results.push_back(SearchResult(url, title));
    }

    return results;
}