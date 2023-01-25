#include <cassert>
#include <iostream>
#include <string_view>
#include <vector>

using namespace std;

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
            str.find_first_not_of(' '), 
            str.size()
        )
    );
    
    while (0<str.size()) {
        int64_t space = str.find(' ');
        std::cout<<space<<std::endl;
        
        result.push_back(
            str.substr(0,space)
        );
        //for(auto x: result) std::cout<<x<<" ";
        //std::cout<<std::endl;
        str.remove_prefix(
            std::min(
                str.find_first_not_of(' '), 
                str.size()
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
