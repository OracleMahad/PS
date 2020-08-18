#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <cstring>
#include <list>
#include <vector>
#include <queue>
#include <cmath>
using namespace std;
int T, N;
int result;
int graph[100001];
int visitD[100001];


//0: untracked, 1 : visited , 2 : cycle , -1: not cycle
void DFS_cycle(int start){
    visitD[start]=1;
	
    if(visitD[graph[start]]==2||visitD[graph[start]]==-1){
        visitD[start] =-1;
        return ;
    }
    else if(visitD[graph[start]]==1){
        for(int i=graph[start];i!=start;i=graph[i]){
            visitD[i]=2;
            result++;
        }
        visitD[start] =2;
        result++;
        return ;
    }
    DFS_cycle(graph[start]);
    if(visitD[start]==1)
        visitD[start]=-1;
}

int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
	cin >> T;
	for(int i=0;i<T;i++){
		memset(visitD,0,sizeof(visitD));
		memset(graph,0,sizeof(graph));
		result=0;
		cin >> N;

		for(int i=1;i<=N;i++){
			cin >> graph[i] ;
		}

		for(int i=1;i<=N;i++){
            if(visitD[i]==0){
                DFS_cycle(i);
            }
		}

		cout << N-result <<"\n";
	}
}