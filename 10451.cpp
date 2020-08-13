#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <cstring>
#include <list>
#include <vector>
#include <queue>
#include <cmath>
using namespace std;
int T, N, result;
int perm[1001];
int visitD[1001];


void DFS(int start){
    // cout << start << " ";
    visitD[start]=1;
    // cout << start << endl;
    if(visitD[perm[start]]==0){
        DFS(perm[start]);
    }
}


int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    cin >> T;
    for(int j=0;j<T;j++){
        memset(visitD,0,sizeof(visitD));
        result=0;
        cin >> N;
        for(int i=1;i<=N;i++){
            cin >> perm[i];
        }
        for(int i=1;i<=N;i++){
            if(visitD[i]==0){
                DFS(i);
                result++;
            }
        }

        cout << result <<"\n";
    }
}