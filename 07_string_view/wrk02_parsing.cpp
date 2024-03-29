#include <cassert>
#include <iostream>
#include <string_view>
#include <vector>

using namespace std;

// g++ --std=c++17 wrk02_parsing.cpp -Wall -Werror -g

/*vector<string_view> SplitIntoWordsView(string_view str) {
    vector<string_view> result;
    int64_t pos = str.find_first_not_of(" ");
    const int64_t pos_end = str.npos;
    
    while (pos != pos_end) {
        int64_t space = str.find(' ', pos);
        result.push_back(space == pos_end ? str.substr(pos) : str.substr(pos, space - pos));
        pos = str.find_first_not_of(" ", space);
    }

    return result;
}*/

vector<string_view> SplitIntoWordsView(string_view str) {
    vector<string_view> result;
    str.remove_prefix(
        std::min(
            str.size(),
            str.find_first_not_of(' ')
        )
    );
    //const int64_t pos_end = str.npos;
    while (0<str.size()) {
        const int64_t space = str.find(' ');
        result.push_back(
            str.substr(0,space)
        );
        str.remove_prefix(
            std::min(
                str.size(),
                str.find(' ')
            )
        );
        str.remove_prefix(
            std::min(
                str.size(),
                str.find_first_not_of(' ')
            )
        );
    }
    return result;
}

int main() {
    assert((SplitIntoWordsView("") == vector<string_view>{}));
    assert((SplitIntoWordsView("     ") == vector<string_view>{}));
    assert((SplitIntoWordsView("aaaaaaa") == vector{"aaaaaaa"sv}));
    /*assert((SplitIntoWordsView("a") == vector{"a"sv}));
    assert((SplitIntoWordsView("a b c") == vector{"a"sv, "b"sv, "c"sv}));
    assert((SplitIntoWordsView("a    bbb   cc") == vector{"a"sv, "bbb"sv, "cc"sv}));
    assert((SplitIntoWordsView("  a    bbb   cc") == vector{"a"sv, "bbb"sv, "cc"sv}));
    assert((SplitIntoWordsView("a    bbb   cc   ") == vector{"a"sv, "bbb"sv, "cc"sv}));
    assert((SplitIntoWordsView("  a    bbb   cc   ") == vector{"a"sv, "bbb"sv, "cc"sv}));*/
    cout << "All OK" << endl;
}
