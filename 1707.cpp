#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <cstring>
#include <string>
#include <cmath>
#include <vector>

using namespace std;
int K, V, E;
vector<int> mat[20001];

int visitD[20001];
string answer;

void DFS_coloring(int start, int color){
    // cout << start << " ";
    visitD[start]=color;
    int another;

    if(color==1){another=2;}// another!=color
    else{another=1;}
    vector<int>::iterator iter;
    for(iter=mat[start].begin();iter!=mat[start].end();iter++){
        if(visitD[*iter]==0){
            DFS_coloring(*iter, another);
        }
        if(visitD[*iter]==color){
            answer="NO";
            return ;
        }
    }

}

int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    
    cin >> K;
    for(int j=0;j<K;j++){
        for(int i=1;i<=V;i++)
            mat[i].clear();
        
        memset(visitD,0,sizeof(visitD));

        answer="YES";
        cin >> V;
        cin >> E;

        for(int i=0;i<E;i++){
            int x, y;
            cin >> x >> y;
            mat[x].push_back(y);
            mat[y].push_back(x);
        }


        
        for(int i=1;i<=V;i++){
            if(visitD[i]==0){
            DFS_coloring(i,1);
            }
        }

        cout << answer << "\n";
    }
    
}