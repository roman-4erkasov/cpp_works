#include <iostream>
#include <stack>

using namespace std;

template <typename Type>
class SortedStack {
public:
    void Push(const Type& element) {
        ++n_push;
        if (elements_.empty()) {
            elements_.push(element);
            return;
        }

        Type last_elem = elements_.top();
        if (last_elem < element) {
            ++n_cmp;
            elements_.pop();
            Push(element);

            elements_.push(last_elem);
        } else {
            elements_.push(element);
        }
    }

    int GetNumOfPushes(){return n_push;}
    int GetNumOfCmp(){return n_cmp;}

    // остальные функции не понадобятся
private:
    stack<Type> elements_;
    int n_cmp=0, n_push=0;
}; 

int main(){
    SortedStack<int> s;
    for(int i=1;i<=100;++i){
        s.Push(i);
    }
    std::cout << "n_cmp="<<s.GetNumOfCmp()<<" n_push="<<s.GetNumOfPushes()<<endl;
    return 0;
}