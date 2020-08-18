#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <cstring>
#include <cmath>
using namespace std;
int w,h;
int island;
char graph[52][52];
int visitD[52][52];
void DFS_co(int x, int y);
void DFS(int x, int y);


void DFS(int x, int y){
    visitD[x][y]=1;

	DFS_co(x+1,y);
	DFS_co(x+1,y-1);
	DFS_co(x,y-1);
	DFS_co(x-1,y-1);

	DFS_co(x-1,y);
	DFS_co(x-1,y+1);
	DFS_co(x,y+1);
	DFS_co(x+1,y+1);
}
void DFS_co(int x, int y){
    if(visitD[x][y]==0 && graph[x][y]=='1'){
        DFS(x,y);
    }
}

int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    while(1){
        memset(visitD,0,sizeof(visitD));
        memset(graph,0,sizeof(graph));
        island=0;

        cin >> w >> h;
        if(w==0&&h==0)break;

        for(int i=1;i<=h;i++){
            for(int j=1;j<=w;j++){
                cin >> graph[i][j];
            }
        }

 

        for(int i=1;i<=h;i++){
            for(int j=1;j<=w;j++){
                if(visitD[i][j]==0 && graph[i][j]=='1'){
                    DFS(i,j);
                    island++;
                }
            }
        }

        cout << island <<"\n";
    }
}