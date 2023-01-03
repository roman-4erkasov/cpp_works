/**
 * Ellegant way to find all the occurences
 * itterating only by found items
*/
#include<string>
#include<algorithm>
#include<iostream>
#include<iterator>

using namespace std;

void PrintSpacesPositions(string& str) {
    // напишите реализацию
    char target = ' ';
    for(
        auto it=find(str.begin(),str.end(),target);
        it!=str.end();
        it=find(next(it),str.end(),target)
    ){
        cout<<distance(str.begin(),it)<<endl;
    }
}

int main() {
    string str = "He said: one and one and one is three"s;
    PrintSpacesPositions(str);
    return 0;
} 