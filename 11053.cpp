#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <limits.h>
#include <cstring>
using namespace std;
int N;
int DP[1001];
int score[1001];
int X[1001];
int main() {
    cin >>N;
    for(int i=1;i<=N;i++){
        cin >> score[i];
    }
    memset(DP,0,sizeof(DP));
    score[0]=0;
    DP[0]=0;

    int answer=0;
    for(int i=1;i<=N;i++){
        DP[i]=1;
        for(int j=1;j<i;j++){
            if(score[i]>score[j]){
                DP[i]=max(DP[j]+1,DP[i]);
            }
        }
        answer=max(answer, DP[i]);
    }
    cout << answer <<endl;
}