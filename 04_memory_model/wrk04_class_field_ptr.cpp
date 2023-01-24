#include <iostream>
using namespace std;

struct A
{
    int a = 10;
};

int main() {
    A obj = A();
    obj.a = 20;

    // check whether I can take a 
    // mutable pointer to a class member
    int * ptr = &(obj.a); 

    // getting typename of a pointer to
    // a class member
    cout << typeid(ptr).name() << endl;;
    // cout gives "Pi"
    return 0;
}
