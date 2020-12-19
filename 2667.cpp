#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <cstring>
#include <vector>
#include <cmath>
using namespace std;
int T, N;
int complex, house;
char graph[27][27];
int visitD[27][27];
vector <int> V;

void DFS(int x, int y){
    visitD[x][y]=1;
	if(visitD[x-1][y]==0&&graph[x-1][y]=='1'){
        DFS(x-1,y);
        house++;
    }
    if(visitD[x+1][y]==0&&graph[x+1][y]=='1'){
        DFS(x+1,y);
        house++;
    }
    if(visitD[x][y-1]==0&&graph[x][y-1]=='1'){
        DFS(x,y-1);
        house++;
    }
    if(visitD[x][y+1]==0&&graph[x][y+1]=='1'){
        DFS(x,y+1);
        house++;
    }
    
}

int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    memset(visitD,0,sizeof(visitD));
    memset(graph,0,sizeof(graph));
    complex=0;
    cin >> N;

    for(int i=1;i<=N;i++){
        for(int j=1;j<=N;j++){
            cin >> graph[i][j];
        }
    }


    for(int i=1;i<=N;i++){
        for(int j=1;j<=N;j++){
            house=1;
            if(visitD[i][j]==0 && graph[i][j]=='1'){
                DFS(i,j);
                complex++;
                V.push_back(house);
            }
        }
    }

    cout << complex <<"\n";
    sort(V.begin(),V.end());
    for(int i=0;i<V.size();i++){
        cout << V[i]<<"\n";
    }

}