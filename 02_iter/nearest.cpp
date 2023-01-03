#include<algorithm>
#include<set>
#include<iostream>
using namespace std;


int dist(int a, int b){
    return a<=b?b-a:a-b;
}


set<int>::const_iterator FindNearestElement(const set<int>& numbers, int border) {
    // set<int>::const_iterator — тип итераторов для константного множества целых чисел
    set<int>::const_iterator right = numbers.lower_bound(border);
    //cout << endl;
    //cout<<"in="<<border<<" d="<<distance(numbers.begin(), right)<<endl;
    if(0<distance(numbers.begin(), right)){
        set<int>::const_iterator left=prev(right);
        int dist_left = dist(border, *left);
        int dist_right = dist(border, *right);
        //cout<<" d(left)="<<dist_left<<" d(right)="<<dist_right<<" "<<endl;
        if(dist_left<=dist_right) return left;
        else return right;
    }
    else {
        return right;
    }
    //cout<<endl;
}

int main() {
    set<int> numbers = {1, 4, 6};
    cout << *FindNearestElement(numbers, 0) << " " << *FindNearestElement(numbers, 3) << " "
         << *FindNearestElement(numbers, 5) << " " << *FindNearestElement(numbers, 6) << " "
         << *FindNearestElement(numbers, 100) << endl;
    set<int> empty_set;
    cout << (FindNearestElement(empty_set, 8) == end(empty_set)) << endl;
    return 0;
}
