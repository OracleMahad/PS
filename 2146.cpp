#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <cstring>
#include <vector>
#include <string>
#include <queue>
#include <climits>

using namespace std;
int N;
int island[102][102];
int cell[102][102];

queue <pair <int, int>> Q;

void BFS(){
    while(!Q.empty()){
        int a, b;
        a=Q.front().first;
        b=Q.front().second;
        Q.pop();

        if(island[a+1][b]!='1'){
            island[a+1][b]='2';
            cell[a+1][b]=cell[a][b]+1;
            Q.push(make_pair(a+1,b));
        }
        if(island[a-1][b]=='1'){
            island[a-1][b]='2';
            cell[a-1][b]=cell[a][b]+1;
            Q.push(make_pair(a-1,b));
        }
        if(island[a][b+1]=='1'){
            island[a][b+1]='2';
            cell[a][b+1]=cell[a][b]+1;
            Q.push(make_pair(a,b+1));
        }
        if(island[a][b-1]=='1'){
            island[a][b-1]='2';
            cell[a][b-1]=cell[a][b]+1;
            Q.push(make_pair(a,b-1));
        }
    }
}

int main(){
    
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    cin >> N; 

    memset(cell, 0, sizeof(cell));
    memset(island, 0, sizeof(island));

    for(int i=1;i<=N;i++){
        for(int j=1;j<=N;j++){
            cin >> island[i][j];
        }
    }
    DFS();
    BFS();

    cout << cell[N][M] << "\n";
    
}
