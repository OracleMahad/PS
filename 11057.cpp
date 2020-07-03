#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <limits.h>
using namespace std;
int N;
int DP[1001][10];
int main() {
    cin >>N;
    for(int i=0;i<10;i++){
        DP[1][i]=1;
    }
    for(int i=2;i<=N;i++){
        for(int j=9;j>=0;j--){
            if(j==9){
                DP[i][j]=DP[i-1][j];
            }
            else{
                DP[i][j]=(DP[i][j+1]+DP[i-1][j])%10007;
            }
            
        }
    }
    int answer=0;
    for(int i=0;i<=9;i++){
        answer=(answer+DP[N][i])%10007;
    }
    cout << answer <<endl;
}