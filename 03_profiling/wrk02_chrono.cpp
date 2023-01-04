#include <iostream>
#include <chrono>
#include <iostream>

int main()
{
    using namespace std;
    using namespace literals;
    // std::chrono::duration<long, std::chrono::hours> hours = 10;
    auto res = chrono::duration_cast<chrono::nanoseconds>(10h).count();
    std::cout << res << " nanoseconds" << endl;
}