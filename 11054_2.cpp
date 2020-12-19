#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <limits.h>
#include <cstring>
#include <vector>
using namespace std;
int A[1002];
int D1[1002];
int D2[1002];
int main(){
    
    int N;
    cin >> N;
    memset(A,0,sizeof(A));
    memset(D1,0,sizeof(D1));
    memset(D2,0,sizeof(D2));

    for(int i =1;i<=N;i++){
        cin >> A[i];
    }
    for(int i=0;i<=N;i++){
        for(int j=0;j<i;j++){
            if(A[i]>A[j]){
                D1[i]=max(D1[i],D1[j]+1);
            }
        }
    }
    for(int i=N+1;i>0;i--){
        for(int j=N+1;j>i;j--){
            if(A[i]>A[j]){
                D2[i]=max(D2[i],D2[j]+1);
            }
        }
    }

    int answer=0;

    for(int i =0;i<=N+1;i++){
        answer=max(answer, D1[i]+D2[i]-1);
    }

    cout << answer << endl;

    
}