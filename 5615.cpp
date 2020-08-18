#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <cstring>
#include <list>
#include <vector>
#include <queue>
#include <cmath>
using namespace std;
int T, N, M, V;
vector <int> graph[100001];
int visitD[1001];

//0: untracked, 2 : cycle
int DFS_cycle(int start){
    cout << start << " ";
    visitD[start]=1;
	vector <int>::iterator iter;
    visit
}

int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
	cin >> T;
	for(int i=0;i<T;i++){
		memset(visitD,0,sizeof(visitD));
		for(int j=1;j<=100001;j++){
			graph[i].clear();
		}
		cin >> N;
		for(int i=1;i<=N;i++){
			int input;
			cin >> input ;
			graph[i].push_back(input);
		}
		for(int i=1;i<=N;i++){
			DFS_cycle(V);
		}

		cout <<"\n";
	}
}