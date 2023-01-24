#include <algorithm>
#include <iostream>
#include <random>
#include <vector>

//g++ wrk01_macrodef.cpp -o a.exe -std=c++17
// g++ wrk01_macrodef.cpp -o find -std=c++17 -D_GLIBCXX_DEBUG -D_GLIBCXX_DEBUG_PEDANTIC -D_LIBCPP_DEBUG=1


using namespace std;

int main() {
    vector v = {1, 81, 100, 50, 70, 30, 90, 200};
    auto iter = upper_bound(v.begin(), v.end(), 80);
    if (iter != v.end()) {
        cout << "Found element "s << *iter << endl;
    }
    return 0;
} 