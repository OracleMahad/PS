#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <limits.h>
using namespace std;
int N;
int T;
int score[100001][2];
int DP[100001][2];
int main() {
    cin >>T;
    for(int t=0;t<T;t++){
        cin >> N;
        for(int i=1;i<=N;i++){
            cin >> score[i][0];
        }
        for(int i=1;i<=N;i++){
            cin >> score[i][1];
        }
        DP[0][0]=0;
        DP[0][1]=0;
        DP[1][0]=score[1][0];
        DP[1][1]=score[1][1];
        for(int i=2;i<=N;i++){
            DP[i][0]=max(DP[i-1][1],DP[i-2][1])+score[i][0];
            DP[i][1]=max(DP[i-1][0],DP[i-2][0])+score[i][1];
        }

        cout << max(DP[N][0],DP[N][1]) <<endl;
    }
}