#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <cstring>
#include <list>
#include <vector>
#include <queue>
#include <cmath>
using namespace std;
int N, M;
int mat[1001][1001];
int visitB[1001];


void BFS(int start){
    queue <int> Q;
    Q.push(start);
    visitB[start]=1;
    while(!Q.empty()){
        int v=Q.front();
        // cout << v <<" ";
        Q.pop();
        for(int i =1;i<=N;i++){
            if(mat[v][i]==1 && visitB[i]==0){
                Q.push(i);
                visitB[i]=1;
            }
        }
    }
}

int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    memset(mat,0,sizeof(mat));
    memset(visitB,0,sizeof(visitB));
    int result=0;
    cin >> N;
    cin >> M;

    for(int i=0;i<M;i++){
        int x, y;
        cin >> x >> y;
        mat[x][y]=1;
        mat[y][x]=1;
    }

    for(int i=1;i<=N;i++){
        if(visitB[i]==0){
            BFS(i);
            result++;
        }
    }
    cout <<result << "\n";
}