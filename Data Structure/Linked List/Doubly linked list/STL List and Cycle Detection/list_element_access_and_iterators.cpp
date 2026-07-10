#include<bits/stdc++.h>
using namespace std;
int main(){
    list<int>l = {1,2,3,4,5,6,6,7,8,7};
    cout<<l.front()<<endl;
    cout<<*l.begin()<<endl;
    cout<<l.back()<<endl;
    cout<<*next(l.begin(), 4)<<endl;
    return 0;
}