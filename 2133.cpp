#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <limits.h>
#include <cstring>
#include <vector>
using namespace std;
int N;
int S[31];
int DP[31];
int main(){
    cin >> N;
    memset(S,0,sizeof(S));
    memset(DP,0,sizeof(DP));
    S[2]=3;
    for(int i=4;i<=30;i=i+2){
        S[i]=2;
    }

    

    for(int i=3;i<=N;i++){
        DP[i]=max(DP[i-2],S[i-1]+DP[i-3])+S[i];
    }
    cout << DP[N] << endl;
}