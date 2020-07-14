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
int spell[26];
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    memset(spell,-1,sizeof(spell));
    
    cin >> order;
    for(int i=0;i<order.size();i++){
        if(spell[(int)order.at(i)-97]==-1)
            spell[(int)order.at(i)-97]=i;
        
    }

    for(int i=0;i<26;i++){
        cout << spell[i] <<" ";
    }
}
