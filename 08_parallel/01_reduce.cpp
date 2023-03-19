#include <iostream>
#include <execution>
#include <list>
#include <numeric>

// g++ -std=c++17 01_reduce.cpp -o 01.exe

int main()
{
    std::list<std::list<int> > lil = {
        {1,2,3},{4,5,6}
    };
    for(const std::list<int> &l: lil){
        for(const int& item: l) {
            std::cout << item << " ";
        }
        std::cout << std::endl;
    }
    std::list<int> result = std::reduce(
        lil.begin(),
        lil.end(),
        // result,
        //decltype(lil)::value_type{},
        std::list<int>{},
        [](auto acc, auto items){
            return acc.insert(
                acc.end(), items.begin(), items.end()
            )
        }
    );
    for(int item: result) {
        std::cout << " " << item;
    }
    std::cout << std::endl;
}