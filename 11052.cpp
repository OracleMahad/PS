#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <limits.h>
#include <cstring>
#include <vector>
#include <string>
using namespace std;
int N;
int P[1001];
int DP[1001];
int main(){
    cin >> N;
    memset(DP,0,sizeof(DP));
    for(int i=1;i<=N;i++){
        cin >> P[i];
        DP[i]=P[i];
    }

    for(int i=2;i<=N;i++){
        for(int j=1;j<i;j++){
            DP[i]=max(DP[i],DP[i-j]+P[j]);
        }
    }


    
    cout << DP[N] << endl;
}