#include <iostream>
using namespace std;
int A[1002];
int D[1002];
int D1[1002];
int D2[1002];
int main(){
    A[0]=0;
    D1[0]=0;
    D2[0]=0;
    int T;
    cin >> T;
    for(int i =1;i<T+1;i++){
        cin >> A[i];
    }
    A[T+1]=0;
    D1[T+1]=0;
    D2[T+1]=0;
    for(int i=0;i<T+1;i++){
        int mx=0;
        for(int j=0;j<i;j++){
            if(A[j]<A[i])  
                if(mx<D1[j]){
                    mx=D1[j];
                }
            D1[i]=mx+1;
        }
    }

    for(int i=T+1;i>0;i--){
        int mx=0;
        for(int j=T+1;j>i;j--){
            if(A[j]<A[i])  
                if(mx<D2[j]){
                    mx=D2[j];
                }
            D2[i]=mx+1;
        }
    }

    for(int i=0;i<T+1;i++){
        D[i]=D1[i]+D2[i];
    }
    int mx=0;
    int index;
    for(int i=0;i<T+1;i++){
        if(mx<D[i]){
            mx=D[i];
            index=i;
        }
    }
    cout << mx-1;
}