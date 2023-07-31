#include <algorithm>
#include <execution>
#include <iostream>
#include <future>
#include <vector>
#include <string>

using namespace std;

// template <typename RandomAccessIterator, typename Value>
// RandomAccessIterator LowerBound(
//     const execution::sequenced_policy&,
//     RandomAccessIterator range_begin, 
//     RandomAccessIterator range_end,
//     const Value& value
// ) 
// {
//     return std::lower_bound(range_begin, range_end, value);
//     /*auto left_bound = range_begin;
//     auto right_bound = range_end;
//     while (left_bound + 1 < right_bound) {
//         const auto middle = left_bound + (right_bound - left_bound) / 2;
//         if (*middle < value) {
//             left_bound = middle;
//         } else {
//             right_bound = middle;
//         }
//     }
//     if (left_bound == range_begin && !(*left_bound < value)) {
//         return left_bound;
//     } else {
//         return right_bound;
//     }*/
// }

template <typename RandomAccessIterator, typename Value>
RandomAccessIterator LowerBound(RandomAccessIterator range_begin, RandomAccessIterator range_end,
                                const Value& value) {
    //return LowerBound(execution::seq, range_begin, range_end, value);
    return std::lower_bound(range_begin, range_end, value);
}

/*
template <typename RandomAccessIterator, typename Value>
RandomAccessIterator LowerBound(const execution::parallel_policy&, RandomAccessIterator range_begin,
                                RandomAccessIterator range_end, const Value& value) {
    return LowerBound(execution::seq, range_begin, range_end, value);
}
*/


// template <typename RandomAccessIterator, typename Value>
// RandomAccessIterator LowerBound(
//     const execution::parallel_policy&,
//     RandomAccessIterator range_begin, 
//     RandomAccessIterator range_end,
//     const Value& value
// )
// {
//     RandomAccessIterator left_bound = range_begin;
//     RandomAccessIterator right_bound = range_end;
    
//     while (left_bound + 1 < right_bound) {
//         const size_t diff = range_end-range_begin;
//         const size_t dist = std::max(1ul,diff/3);
//         const auto middle_left = left_bound + dist;
//         const auto middle_right = right_bound - dist;
//         future<bool> not_left_third = async(
//             [middle_left, value]{return *middle_left<value;}
//         );
//         //if(*middle_right < value) {
//         //    right_bound = middle_left;
//         //    continue;
//         //}
//         //future<RandomAccessIterator> result_middle = LowerBound(middle_left, middle_right, value);
//         //RandomAccessIterator result_left = LowerBound(left_bound, middle_left, value);

//         if(*middle_right < value) // right third
//         {
//             left_bound = middle_right;
//         } 
//         else if(not_left_third.get()) //middle third
//         {
//            left_bound = middle_left;
//            right_bound = middle_right;
//         } else //left third
//         {
//             right_bound = middle_left;
//         }
//     }
//     std::cout <<"<" << *left_bound <<","<<*right_bound<<">"<<std::endl;
//     if(left_bound == range_begin && !(value < *range_begin)){
//         std::cout << "!!!!"<<std::endl;
//         return left_bound;
//     }
//     return right_bound;
// }



int main() {
    const vector<string> strings = {"cat"s, "dog"s, "dog"s, "horse"s};
    const vector<string> requests = {"bear", "cat", "deer", "dog", "dogs", "horses"};
    
    for(string req: requests){
        auto res_seq = LowerBound(strings.begin(), strings.end(), req);
        if(res_seq==strings.begin()){
            std::cout<<"req="<<req << " seq="<<*res_seq<<std::endl;
        }
        // auto res_par = LowerBound(execution::par, strings.begin(), strings.end(), req);
        // if(*res_seq!=*res_par){
        //     std::cout<<"req="<<req << " seq="<<*res_seq<<" par="<<*res_par<<std::endl;
        // }
    }
    
    /*
    // последовательные версии
    cout << "Request [" << requests[0] << "] → position "
         << LowerBound(strings.begin(), strings.end(), requests[0]) - strings.begin() << endl;
    cout << "Request [" << requests[1] << "] → position "
         << LowerBound(execution::seq, strings.begin(), strings.end(), requests[1])
            - strings.begin()
         << endl;
    cout << "Request [" << requests[2] << "] → position "
         << LowerBound(execution::seq, strings.begin(), strings.end(), requests[2])
            - strings.begin()
         << endl;

    // параллельные
    cout << "Request [" << requests[3] << "] → position "
         << LowerBound(execution::par, strings.begin(), strings.end(), requests[3])
            - strings.begin()
         << endl;
    cout << "Request [" << requests[4] << "] → position "
         << LowerBound(execution::par, strings.begin(), strings.end(), requests[4])
            - strings.begin()
         << endl;
    cout << "Request [" << requests[5] << "] → position "
         << LowerBound(execution::par, strings.begin(), strings.end(), requests[5])
            - strings.begin()
         << endl;
    */
}