#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <limits.h>
#include <cstring>
#include <vector>
using namespace std;
int N;
int K;
int DP[201][201];
int main(){
    cin >> N;
    cin >> K;
    memset(DP,0,sizeof(DP));
    for(int i=0;i<=N;i++){
        DP[i][1]=1;
    }
    for(int i=2;i<=K;i++){
        for(int j=0;j<=N;j++){
            for(int k=0;k<=j;k++){ 
                DP[j][i]=(DP[j][i]+DP[j-k][i-1])%1000000000;
            } 
        }
    }
    cout << DP[N][K] << endl;
}