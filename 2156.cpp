#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <limits.h>
using namespace std;
int N;
int DP[10001];
int score[10001];
int main() {
    cin >>N;
    for(int i=1;i<=N;i++){
        cin >> score[i];
    }
    score[0]=0;
    DP[0]=0;
    DP[1]=score[1];
    DP[2]=score[1]+score[2];
    DP[3]=max(score[2]+DP[0], DP[1])+score[3];
    for(int i=4;i<=N;i++){
        DP[i]=max(max(score[i-1]+DP[i-4],score[i-1]+DP[i-3]), DP[i-2])+score[i];
    }
    int answer=0;
    for(int i=1;i<=N;i++){
        answer=max(answer, DP[i]);
    }
    cout << answer <<endl;
}