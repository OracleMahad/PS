#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <cstring>
#include <vector>

using namespace std;
int N;
vector <int> node[100001];
int parent[100001];
void DFS(int start, int par){
    parent[start]=par;
    vector <int>::iterator iter;
    for(iter=node[start].begin();iter!=node[start].end();iter++){
        if(parent[*iter]==0){
            DFS(*iter, start);
        }
    }
}

int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    cin >> N;
    memset(parent,0,sizeof(parent));
    for(int i=1;i<N;i++){
        int a,b;
        cin >> a >> b ;
        node[a].push_back(b);
        node[b].push_back(a);
    }

    DFS(1 , 1);

    for(int i=2;i<=N;i++){
        cout << parent[i] <<"\n";
    }


}
