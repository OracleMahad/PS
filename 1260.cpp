#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <cstring>
#include <list>
#include <vector>
#include <queue>
#include <cmath>
using namespace std;
int N, M, V;
int mat[1001][1001];
int visitD[1001];
int visitB[1001];

void DFS(int start){
    cout << start << " ";
    visitD[start]=1;
    for(int i =1;i<=N;i++){
        if(mat[start][i]==1 && visitD[i]==0){
            DFS(i);
        }
    }
}

void BFS(int start){
    queue <int> Q;
    Q.push(start);
    visitB[start]=1;
    while(!Q.empty()){
        int v=Q.front();
        cout << v <<" ";
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
    memset(visitD,0,sizeof(visitD));
    memset(visitB,0,sizeof(visitB));

    cin >> N;
    cin >> M;
    cin >> V;
    for(int i=0;i<M;i++){
        int x, y;
        cin >> x >> y;
        mat[x][y]=1;
        mat[y][x]=1;
    }

    DFS(V);
    cout <<"\n";
    BFS(V);
    cout <<"\n";
}