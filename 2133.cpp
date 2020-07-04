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
    DP[2]=S[2];
    for(int i=4;i<=N;i=i+2){
        int sum=0;
        for(int j=2;j<=i-2;j=j+2){
            sum=sum+DP[j]*S[i-j];
        }
        DP[i]=sum+S[i];
    }
    cout << DP[N] << endl;
}