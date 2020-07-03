#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <limits.h>
#include <cstring>
#include <vector>
using namespace std;
int N;
int DP[100001];
int main(){

    cin >> N;
    memset(DP,0,sizeof(DP));
    for(int i =1;i<=N;i++){
        cin >> S[i];
    }
    DP[1]=S[1];
    DP[2]=S[1]+S[2];

    for(int i=3;i<=N;i++){
        DP[i]=max(DP[i-2],S[i-1]+DP[i-3])+S[i];
    }
    cout << DP[N] << endl;
}