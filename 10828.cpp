#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <limits.h>
#include <cstring>
#include <vector>
#include <string>
using namespace std;
int N;
void useStack(string s);
string order;
vector<int> v;
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    cin >> N;
    
    for(int i=0;i<N;i++){
        cin >> order;
        useStack(order);
    }

}
void useStack(string s){
    if(s=="push"){
        int pushX;
        cin >> pushX;
        v.push_back(pushX);
    }
    if(s=="pop"){
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
    if(s=="top"){
        if(v.empty())
            cout << -1 << "\n";
        else
            cout << v.back() << "\n";
    }
}