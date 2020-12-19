#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <limits.h>
using namespace std;
int N;
long long DP[91];
int main() {
    cin >>N;
    DP[1]=1;
    DP[2]=1;
    for(int i=3;i<=N;i++){
       DP[i]=DP[i-1]+DP[i-2];
    }
    cout << DP[N] <<endl;
}