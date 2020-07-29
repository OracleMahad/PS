#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <string>
#include <list>
using namespace std;
int N;
string order;
string str;

int main(){
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    cin >> str;
    cin >> N;

    list<char> edit(str.begin(),str.end());
    list<char>::iterator cursor = edit.end();
    auto c= edit.end();
    for(int i=0;i<N;i++){
        cin >> order;
        if(order=="L"&&cursor!=edit.begin()){
            cursor--;
        }
        if(order=="D"&&cursor!=edit.end()){
            cursor++;
        }
        if(order=="B"&&cursor!=edit.begin()){
            c=cursor;
            c--;
            edit.erase(c);
        }
        if(order=="P"){
            char input;
            cin >> input;
            edit.insert(cursor,input);
        }
    }
    for(cursor=edit.begin();cursor!=edit.end();cursor++){
        cout << *cursor;
    }
}