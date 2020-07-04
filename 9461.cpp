#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <limits.h>
#include <cstring>
#include <vector>
using namespace std;
int N;
int T;
long long DP[101];
int main(){
    cin >> T;
    for(int i=1;i<=T;i++){
        cin >> N;
        DP[1]=1;
        DP[2]=1;
        DP[3]=1;
        DP[4]=2;
        DP[5]=2;

        for(int j=6;j<=N;j++){
            DP[j]=DP[j-5]+DP[j-1];
        }
        cout << DP[N] << endl;
    }

}