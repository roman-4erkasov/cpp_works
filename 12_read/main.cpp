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
        ss.clear();
        ss << "store=[";
        for(User* ptr: sorted_){
            if(first) first=false;
            else ss << ", ";
            ss <<"<"<<ptr->user_id<<","<<ptr->page_num<<">";
        }
        ss << "]";
        return ss.str();
    }
    std::string DescribeUser2Idx(){
        bool first = true;
        std::stringstream ss;
        ss << "user2idx={";
        for(const auto& [user_id, idx]:user2idx_) {
            if(first) first=false;
            else ss << ", ";
            ss <<"<"<<user_id<<":"<<idx<<">";
        }
        ss << "}";
        return ss.str();
    }

    index_t MoveUpdatedUser(index_t user_id){
        int curr=user2idx_[user_id],
            next=curr+1;
        while (
            next < sorted_.size()
            &&
            sorted_[curr]->page_num > sorted_[next]->page_num
        )
        {
            
            user2idx_[sorted_.at(next)->user_id] = curr;
            user2idx_[sorted_.at(curr)->user_id] = next;
            std::swap(sorted_[curr], sorted_[next]);
            curr++;
            next++;
        }
        return curr-1;
    }
    void CorrectAfterInsert(index_t user_id){
        size_t idx = user2idx_[user_id];
        for(size_t i=idx+1; i<sorted_.size();++i) {
            user2idx_[sorted_.at(i)->user_id]++;
        }
    }

    void SetUser(const index_t user_id, const number_t page) {
        if(is_debug) {
            std::cout << "[SetUser] before: item=<" << user_id << "," << page <<"> ";
            std::cout << DescribeSorted() << " ";
            std::cout << DescribeUser2Idx() << std::endl;
        }
        if(user2idx_.count(user_id)) {
            size_t idx = user2idx_.at(user_id);
            sorted_[idx]->page_num = page;
            
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
        idx++;
        while (idx<sorted_.size() && sorted_[idx]<sorted_[idx-1]) {
            std::cout 
                << "[u2i] "
                << sorted_[idx]->user_id << ": "
                << idx << " -> " << idx-1 << std::endl;
            user2idx_[sorted_[idx]->user_id] = idx-1;
            std::swap(sorted_[idx-1],sorted_[idx]);
            idx++;

        }
        while (idx<sorted_.size()){
            std::cout 
                << "[u2i] "
                << sorted_[idx]->user_id << ": "
                << idx << " -> " << idx+1 << std::endl;
            user2idx_[sorted_[idx]->user_id] = idx+1;
            idx++;
        }
        user2idx_[user_id] = idx;
        if(is_debug){
            std::cout << "[SetUser] after:" << DescribeSorted() 
            <<" " << DescribeUser2Idx() << std::endl;
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
