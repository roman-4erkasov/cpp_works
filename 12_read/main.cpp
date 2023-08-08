#include <iostream>
#include <unordered_map>
#include <deque>
#include <algorithm>
#include <memory>
#include <sstream>

using index_t = int;
using number_t = int;

struct User {
    index_t user_id;
    number_t page_num;
};

class LibraryApp {
public:
    LibraryApp()=default;
    LibraryApp(bool debug){
        is_debug = debug;
    }

    std::string DescribeSorted() {
        bool first = true;
        std::stringstream ss;
        ss << "store=[";
        for(User* ptr: sorted_){
            if(first) first=false;
            else std::cout << ", ";
            ss <<"<"<<ptr->user_id<<","<<ptr->page_num<<">";
        }
        ss << "]"<<std::endl;
        return ss.str();
    }
    std::string DescribeUser2Idx(){
        bool first = true;
        std::stringstream ss;
        ss << "user2idx={";
        for(const auto& [user_id, idx]:user2idx_) {
            if(first) first=false;
            else std::cout << ", ";
            ss <<"<"<<user_id<<":"<<idx<<">";
        }
        return ss.str();
    }

    void SetUser(const index_t user_id, const number_t page) {
        if(is_debug){
            std::cout << "[SetUser] before: item=<" << user_id << "," << page <<"> ";
            std::cout << DescribeSorted();
            std::cout << DescribeUser2Idx() << std::endl;
        }
        if(user2idx_.count(user_id)) {
            size_t idx = user2idx_.at(user_id);
            sorted_[idx]->page_num = page;
            idx++;
            while (idx<sorted_.size() && sorted_[idx]<sorted_[idx-1]) {
                user2idx_[sorted_[idx]->user_id] = idx-1;
                std::swap(sorted_[idx-1],sorted_[idx]);
                idx++;

            }
            while (idx<sorted_.size()){
                user2idx_[sorted_[idx]->user_id] = idx+1;
                idx++;
            }
            user2idx_[user_id] = idx;
        }
        else {
            User* user_ptr = new User{user_id, page};
            auto it = std::upper_bound(
                sorted_.begin(),
                sorted_.end(), 
                user_ptr,
                [](User* lhs, User* rhs) -> bool {
                    return lhs->page_num<rhs->page_num;
                }
            );
            auto res = sorted_.insert(it, user_ptr);
            user2idx_[user_id] = std::distance(sorted_.begin(), res);
        }
        if(is_debug){
            std::cout << "[SetUser] after:" << DescribeSorted() << DescribeUser2Idx() << std::endl;
        }
    }

    number_t NumOfSlowerUsers(const index_t user_id) const {
        return static_cast<number_t>(user2idx_.at(user_id));
    }
    
private:
    std::deque<User*> sorted_;
    std::unordered_map<index_t, size_t> user2idx_;
    bool is_debug = false;
};

int main(int argc, char const *argv[])
{
    LibraryApp lib(true);
    lib.SetUser(0,1);
    lib.SetUser(1,2);
    lib.SetUser(2,0);
    std::cout << lib.NumOfSlowerUsers(0) << std::endl;
    std::cout << lib.NumOfSlowerUsers(1) << std::endl;
    std::cout << lib.NumOfSlowerUsers(2) << std::endl;
    return 0;
}
