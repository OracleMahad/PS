#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <limits.h>
#include <cstring>
#include <vector>
using namespace std;
int N;
int A[100001];
int DP[100001];
int main(){
    int answer=-INT_MAX;
    cin >> N;
    memset(DP,0,sizeof(DP));
    for(int i =1;i<=N;i++){
        cin >> A[i];
    }
    for(int i=1;i<=N;i++){
        DP[i]=max(DP[i-1],0)+A[i];
        answer= max(DP[i],answer);
    }
    cout << answer << endl;

    
}