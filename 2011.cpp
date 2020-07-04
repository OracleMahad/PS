#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <limits.h>
#include <cstring>
#include <vector>
using namespace std;
int N;
int K;
char
int S[27];
int DP[5001];
int main(){
    cin >> N;
    memset(DP,0,sizeof(DP));
    S[0]=0;
    for(int i=1;i<=26;i++){
        S[i]=1;
    }
    for(int i=0;i<=N;i++){
        DP[i]=(DP[i]+DP[i/10]*S[i%10]+DP[i/100]*S[i%100])%1000000;
    }
    cout << DP[N] << endl;
}