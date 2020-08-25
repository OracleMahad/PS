#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <cstring>
#include <vector>
#include <string>
#include <queue>
#include <climits>

using namespace std;
int M, N;
char maze[102][102];
int cell[102][102];

queue <pair <int, int>> Q;

void BFS(){
    Q.push(make_pair(1,1));
    maze[1][1]=2;
    cell[1][1]=1;
    while(!Q.empty()){
        int a, b;
        a=Q.front().first;
        b=Q.front().second;
        Q.pop();

        if(maze[a+1][b]=='1'){
            maze[a+1][b]='2';
            cell[a+1][b]=cell[a][b]+1;
            Q.push(make_pair(a+1,b));
        }
        if(maze[a-1][b]=='1'){
            maze[a-1][b]='2';
            cell[a-1][b]=cell[a][b]+1;
            Q.push(make_pair(a-1,b));
        }
        if(maze[a][b+1]=='1'){
            maze[a][b+1]='2';
            cell[a][b+1]=cell[a][b]+1;
            Q.push(make_pair(a,b+1));
        }
        if(maze[a][b-1]=='1'){
            maze[a][b-1]='2';
            cell[a][b-1]=cell[a][b]+1;
            Q.push(make_pair(a,b-1));
        }
    }
}

int main(){
    
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    cin >> N >> M; 

    memset(cell, 0, sizeof(cell));
    memset(maze, 0, sizeof(maze));

    for(int i=1;i<=N;i++){
        for(int j=1;j<=M;j++){
            cin >> maze[i][j];
        }
    }

    BFS();

    cout << cell[N][M] << "\n";
    
}
