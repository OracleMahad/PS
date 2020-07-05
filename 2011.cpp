#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <limits.h>
#include <cstring>
#include <vector>
#include <string>

using namespace std;
int S[100];
int DP[5001];
int main(){
    string str;
    cin >> str;
    memset(DP,0,sizeof(DP));
    memset(S,0,sizeof(S));
    S[0]=0;
    for(int i=1;i<=26;i++){
        S[i]=1;
    }
    DP[0] = S[(int)str.at(0)-48];
    if(str.size()>1)
        DP[1] = S[((int)str.at(0)-48)*10+((int)str.at(1)-48)]*S[((int)str.at(0)-48)]+S[(int)str.at(0)-48]*S[(int)str.at(1)-48];
    for(int i=2;i<str.size();i++){
            DP[i]=(DP[i-1]*S[(int)str.at(i)-48] + DP[i-2]*S[((int)str.at(i-1)-48)*10+((int)str.at(i)-48)]*S[((int)str.at(i-1)-48)])%1000000;
    }
    cout << DP[str.size()-1] << endl;
}