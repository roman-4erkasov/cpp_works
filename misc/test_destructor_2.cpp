#include <iostream>
#include <string>

using namespace std;

class Fruit {
public:
    Fruit(const string& name)
        : name_(name) {
        cout << "+"s << name_;
    }
    ~Fruit() {
        cout << "-"s << name_;
    }
private:
    string name_;
};

int main() {
    Fruit mango{"mango"s};

    for (string s : {"apple"s, "banana"s}) {
        Fruit fruit{s};
        if (s.length() % 2 == 0) {
            Fruit another_fruit{s};
            cout << "?"s;
        }
        cout << "!"s;
    }
} 