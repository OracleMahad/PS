#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <string>
#include <list>
using namespace std;
int N;
int K;
string order;
string str;
list<int> lst;
list<int>::iterator point;
list<int>::iterator point2;

void next_node(){
    point++;
    if(point==lst.end()){
        point=lst.begin();
    }
}

int main(){
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    cin >> N;
    cin >> K;
    for(int i=1;i<=N;i++){
        lst.push_back(i);
    }

    point = lst.begin();
    for(int i=1;i<K;i++){
        next_node();
    }
    while(!lst.empty()){
        cout << *point;
        point=lst.erase(point);
        for(int i=1;i<K;i++){
            next_node();
        }
    }
}