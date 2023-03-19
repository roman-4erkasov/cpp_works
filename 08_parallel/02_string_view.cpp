#include <map>
#include <string_view>
#include <string>

int main()
{
    std::string steve = "steve";
    std::string erica = "erica";

    std::map<std::string_view, int> tests = {
        { steve, 7 },
        { erica, 10 }
    };

    int total = tests["steve"] + tests["erica"];
    return total;
}

// #include <iostream>
// #include <vector>
// #include <map>
// #include <string>
// #include <string_view>

// using namespace std;

// int main(int argc, char const *argv[])
// {
//     // vector<string> vec = {"aa"s,"bb"s,"cc"s};
//     string a = "a"s, b = "b"s;

//     map<string_view,int> dict={{a, 1}};
//     // dict.insert({vec[0], 1});
//     // std::cout << "{";
//     // for(auto[str, val]: dict){
//     //     std::cout << str << ":" << val << ",";
//     // }
//     // std::cout << "}" << std::endl;
//     return 0;
// }
