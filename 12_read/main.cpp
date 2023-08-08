#include <iostream>
#include <unordered_map>
#include <deque>
#include <algorithm>
#include <memory>

using index_t = int;
using number_t = int;

struct User {
    index_t user_id;
    number_t page_num;
};

class LibraryApp {
public:
    void SetUser(const index_t user_id, const number_t page) {
        if(user2idx_.count(user_id)) {
            size_t idx = user2idx_.at(user_id);
            sorted_[idx]->page_num = page;
            idx++;
            while (idx<sorted_.size() && sorted_[idx]<sorted_[idx-1]) {
                std::swap(sorted_[idx-1],sorted_[idx]);
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
    }

    number_t NumOfSlowerUsers(const index_t user_id) const {
        return static_cast<number_t>(user2idx_.at(user_id));
    }
    
private:
    std::deque<User*> sorted_;
    std::unordered_map<index_t, size_t> user2idx_;
};

int main(int argc, char const *argv[])
{
    LibraryApp lib;
    lib.SetUser(0,1);
    lib.SetUser(1,2);
    std::cout << lib.NumOfSlowerUsers(0) << std::endl;
    std::cout << lib.NumOfSlowerUsers(1) << std::endl;
    return 0;
}
