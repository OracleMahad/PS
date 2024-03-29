#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <cstring>
#include <vector>

using namespace std;
int V;
vector <pair <int ,int>> tree[100001];
int visit[100001];
int max_len=0;
int y, z;
void DFS(int start, int len){
    visit[start]=1;
    vector <pair <int ,int>>::iterator iter;
    for(iter= tree[start].begin();iter!=tree[start].end();iter++){
        if(visit[iter->first]==0){
            int newlen=len+(iter->second);
            if(max_len<newlen){
                max_len=newlen;
                y=iter->first;
            }
            DFS(iter->first, newlen);
        }
    }
}


int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    cin >> V;

    for(int i=1;i<=V;i++){
        int a, b, c;
        cin >> a;
        while(1){
            cin >> b;
            if(b==-1)break;
            cin >> c;
            tree[a].push_back(make_pair(b,c));
            // tree[b].push_back(make_pair(a,c));
        }
    }
    memset(visit,0,sizeof(visit));
    DFS(1,0);
    memset(visit,0,sizeof(visit));
    max_len = 0;
    DFS(y,0);
    cout << max_len << "\n";

}
