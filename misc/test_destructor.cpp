#include <iostream>
#include <string>

using namespace std;

class Cat {
public:
    Cat(const string& name)
        : name_(name) {
        cout << "c-"s << name_;
    }
    void Meow() const {
        cout << "-meow-"s;
    }
    ~Cat() {
        cout << "d-"s << name_;
    }
private:
    string name_;
};

int main() {
    Cat cat("tom"s);
    cat.Meow();
}