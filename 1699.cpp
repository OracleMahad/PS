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
    for(int i =1;i<=N;i++){
        DP[i]=i;
    }
    
    for(int i=5;i<=N;i++){
        for(int j=1;j*j<=i;j++){
            DP[i]=min(DP[i],DP[i-j*j]+1);
        }
    }
    cout << DP[N] << endl;
}