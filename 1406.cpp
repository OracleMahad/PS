#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <limits.h>
#include <cstring>
#include <vector>
#include <string>
using namespace std;
int N;
int cursor;
void edit(string s);
string order;
string str;

int main(){
    cin.tie(0);
    ios_base::sync_with_stdio(false);

    cin >> str;
    cin >> N;
    cursor = str.size();
    for(int i=0;i<N;i++){
        cin >> order;
        edit(order);
    }
    cout << str;
}
void edit(string s){
    if(s=="L"&&cursor!=0){
        cursor--;
    }
    if(s=="D"&&cursor<str.length()){
        cursor++;
    }
    if(s=="B"&&cursor!=0){
        str.replace(cursor-1,1,"");
        cursor--;
    }
    if(s=="P"){
        string input;
        cin >> input;
        str.replace(cursor,0,input);
        cursor+=input.length();
    }

}