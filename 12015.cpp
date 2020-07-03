#include <iostream>
#include <string.h>
using namespace std;
int A[1000001];
int D[1000001];
int X[1000001];
int main() {
	int N;
    int mxl=0;
	cin >> N ;
    for(int i=1;i<N+1;i++){
        cin >> A[i];
    }
    memset(D,0,sizeof(D));
    memset(X,-1,sizeof(X));
    A[0]=0;
    X[0]=0;
    for(int i=0;i <N+1;i++){
        int index=0;
        while(X[index]<A[i]&&X[index]!=-1){
            index++;
        }
        if(X[index]==-1||X[index]>A[i]){
            X[index]=A[i];
        }
        D[i]=index;
    }
    for(int i=0;i<N+1;i++){
        if(mxl<D[i])
          mxl=D[i];
    }
    cout << mxl << endl;
}
