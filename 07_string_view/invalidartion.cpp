#include <string>
#include <string_view>
#include <iostream>

class SearchServer {
public:
    struct Query{
        std::string_view value;
    };
    Query ParseQuery(std::string raw_query){
        std::cout << "ParseQueries:" << raw_query<<std::endl;
        return {raw_query};
    }
    void FindTopDocuments(std::string_view raw_query) {
        Query query = ParseQuery(std::string(raw_query));
        std::cout << "FindTopDocuments: query = Query(value="
            << query.value << ")" << std::endl;
    }
};

using namespace std;

int main(int argc, char const *argv[])
{
    SearchServer server;
    server.FindTopDocuments("abcde"s);
    return 0;
}
