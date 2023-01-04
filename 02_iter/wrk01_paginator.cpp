/**
 * Experiment how to iterate by multiple items using iterators.
 * Compilation: g++ -std=c++17 wrk01_paginator.cpp
*/

#include <algorithm>
#include <cmath>
#include <iostream>
#include <map>
#include <set>
#include <stdexcept>
#include <string>
#include <utility>
#include <vector>
#include <iostream>
#include <iterator>
#include <numeric>

template<typename Iterator>
class Page{
public:
    Page(Iterator begin, Iterator end)
    :begin_(begin), end_(end)
    {}
    auto begin() const {
        return begin_;
    }
    auto end() const {
        return end_;
    }
private:
    Iterator begin_, end_;
};

template <typename Iterator>
std::ostream& operator<<(std::ostream& os, const Page<Iterator>& page)
{
    //std::ostream_iterator<int> out_it (os, "");
    //std::copy(page.begin(), page.end(), out_it );
    bool is_begin=true;
    for(Iterator it=page.begin();it!=page.end();++it){
        if(is_begin) is_begin=false;
        else os<<' ';
        os<<*it;
    }
    return os;
}

template<typename Iterator>
class Paginator{
public:
    Paginator(Iterator begin, Iterator end, int page_size=2)
    :page_sz(page_size)
    {
            auto ibeg=begin;
            auto iend=std::next(ibeg, page_sz);
            while(0<std::distance(iend,end)){
                pages_.push_back(Page(ibeg,iend));
                ibeg=iend;
                iend=std::next(ibeg, page_sz);
            }
            if(0<std::distance(ibeg,end))
                pages_.push_back(Page(ibeg,end));
    }
    auto begin() const {
        return pages_.begin();
    }
    auto end() const {
        return pages_.end();
    }
private:
    std::vector<Page<Iterator> > pages_;
    int page_sz;
    //Iterator begin_, end_;
};

int main()
{
    std::vector<int> vec(10);
    std::iota(vec.begin(),vec.end(),0);
    for(auto it=vec.begin(); it!=vec.end();++it)
        std::cout<<*it<<" ";
    std::cout<<std::endl;

    Paginator pages = Paginator(vec.begin(),vec.end(),3);
    for(auto page=pages.begin();page!=pages.end();++page)
        std::cout<<*page<<std::endl;
    
    return 0;
}
