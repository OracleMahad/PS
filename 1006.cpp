#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <limits.h>
#include <cstring>
using namespace std;
int T;
int N;
int W;
int answer;
int S[10001][2];
int A[10001];
int B[10002];
int C[10002];
void solve(int start){
    for(int i=start;i<=N;i++){
        A[i]=min(B[i-1]+1,C[i-1]+1);
        if(S[i][0]+S[i][1]<=W){
            A[i]=min(A[i],A[i-1]+1);
        }
        if(S[i][0]+S[i-1][0]<=W && S[i][1]+S[i-1][1]<=W && i>start){
            A[i]=min(A[i],A[i-2]+2);
        }
        B[i]=A[i]+1;
        if(S[i][1]+S[i+1][1]<=W){        
            B[i]=min(B[i],C[i-1]+1);
        }

        C[i]=A[i]+1;
        if(S[i][0]+S[i+1][0]<=W){        
            C[i]=min(C[i],B[i-1]+1);
        }
    }
}
int main() {
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    cin >> T;
    for(int t=0;t<T;t++){
        cin >>N;
        cin >> W;
        for(int i=1;i<=N;i++){
            cin >> S[i][0];
        }
        for(int i=1;i<=N;i++){
            cin >> S[i][1];
        }

        memset(A,0,sizeof(A));
        memset(B,0,sizeof(B));
        memset(C,0,sizeof(C));
        B[0]=1;
        C[0]=1;
        solve(1);
        answer=A[N];


        if(S[1][1]+S[N][1]<=W){
            memset(A,0,sizeof(A));
            memset(B,0,sizeof(B));
            memset(C,0,sizeof(C));
            A[1]=1;
            B[1]=2;
            C[1]=2;
            if(S[1][0]+S[2][0]<=W)
                C[1]=1;
            solve(2);
            answer=min(answer, C[N-1]+1);
        }
        if(S[1][0]+S[N][0]<=W){
            memset(A,0,sizeof(A));
            memset(B,0,sizeof(B));
            memset(C,0,sizeof(C));
            A[1]=1;
            B[1]=2;
            C[1]=2;
            if(S[1][1]+S[2][1]<=W)
                B[1]=1;
            solve(2);
            answer=min(answer, B[N-1]+1);
        }
        if(S[1][1]+S[N][1]<=W && S[1][0]+S[N][0]<=W){
            memset(A,0,sizeof(A));
            memset(B,0,sizeof(B));
            memset(C,0,sizeof(C));
            B[1]=1;
            C[1]=1;
            solve(2);
            answer=min(answer, A[N-1]+2);
        }
        if(N==1){
            answer= 2;

            if(S[1][0]+S[1][1]<=W)
                answer= 1;
        }
        cout << answer <<"\n";
    }
}
