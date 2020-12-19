#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <limits.h>
#include <cstring>
#include <vector>
#include <string>
using namespace std;
int N;
void useQ(string s);
string order;
vector<int> v;
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    cin >> N;
    
    for(int i=0;i<N;i++){
        cin >> order;
        useQ(order);
    }

}
void useQ(string s){
    if(s=="push_front"){
        int pushX;
        cin >> pushX;
        v.insert(v.begin(),1,pushX);
    }
    if(s=="push_back"){
        int pushX;
        cin >> pushX;
        v.push_back(pushX);
    }
    if(s=="pop_front"){
        if(v.empty()){cout << -1 << "\n";}
        else{
            cout << v.front() << "\n";
            v.erase(v.begin());
        }
    }
    if(s=="pop_back"){
        if(v.empty()){cout << -1 << "\n";}
        else{
            cout << v.back() << "\n";
            v.pop_back();
        }
    }
    if(s=="size"){
        cout << v.size() << "\n";
    }
    if(s=="empty"){
        cout << v.empty() << "\n";
    }
    if(s=="front"){
        if(v.empty())
            cout << -1 << "\n";
        else
            cout << v.front() << "\n";
    }
    if(s=="back"){
        if(v.empty())
            cout << -1 << "\n";
        else
            cout << v.back() << "\n";
    }
}