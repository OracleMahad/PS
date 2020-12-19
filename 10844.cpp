#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <limits.h>
using namespace std;
int N;
int DP[101][10];
int main() {
    cin >>N;
    for(int i=0;i<10;i++){
        DP[1][i]=1;
    }
    for(int i=2;i<=N;i++){
        for(int j=0;j<=9;j++){
            if(j==0){
                DP[i][j]=DP[i-1][j+1];
            }
            else if(j==9){
                DP[i][j]=DP[i-1][j-1];
            }
            else{
                DP[i][j]=(DP[i-1][j+1]+DP[i-1][j-1])%1000000000;
            }
        }
    }
    int answer=0;
    for(int i=1;i<=9;i++){
        answer=(answer+DP[N][i])%1000000000;
    }
    cout << answer <<endl;
}