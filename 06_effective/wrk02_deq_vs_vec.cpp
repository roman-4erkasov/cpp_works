#include <vector>
#include <deque>
#include <random>
#include <algorithm>
#include "../03_profiling/log_duration.hpp"

/*
cab-wsm-0694637:06_effective 08355818$ g++ wrk01_deq_vs_vec.cpp -std=c++17
cab-wsm-0694637:06_effective 08355818$ ./a.out 
1kk with vector: 165 ms
1kk with deque: 165 ms
5kk with vector: 751 ms
5kk with deque: 774 ms
1kkk with vector: 166152 ms
1kkk with deque: 167855 ms
cab-wsm-0694637:06_effective 08355818$ 
*/

int main(){
    std::random_device dev;
    std::mt19937 rng(dev());
    std::uniform_int_distribution<std::mt19937::result_type> dist6(1,100000);
    std::vector<int> vec;
    for(int i=0;i<1000000;++i){
        vec.push_back(dist6(rng));
    }
    {
        LOG_DURATION("1kk with vector");
        std::sort(vec.begin(), vec.end());
    }
    std::deque<int> deq;
    for(int i=0;i<1000000;++i){
        deq.push_back(dist6(rng));
    }
    {
        LOG_DURATION("1kk with deque");
        std::sort(deq.begin(), deq.end());
    }
    
    return 0;
}