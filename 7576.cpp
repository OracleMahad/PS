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
int tmt[1002][1002];
int day[1002][1002];

queue <pair <int, int>> Q;

void BFS_t(){

    while(!Q.empty()){
        int a, b;
        a=Q.front().first;
        b=Q.front().second;
        Q.pop();

        if(tmt[a+1][b]==0){
            tmt[a+1][b]=1;
            day[a+1][b]=day[a][b]+1;
            Q.push(make_pair(a+1,b));
        }
        if(tmt[a-1][b]==0){
            tmt[a-1][b]=1;
            day[a-1][b]=day[a][b]+1;
            Q.push(make_pair(a-1,b));
        }
        if(tmt[a][b+1]==0){
            tmt[a][b+1]=1;
            day[a][b+1]=day[a][b]+1;
            Q.push(make_pair(a,b+1));
        }
        if(tmt[a][b-1]==0){
            tmt[a][b-1]=1;
            day[a][b-1]=day[a][b]+1;
            Q.push(make_pair(a,b-1));
        }
    }
}

int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    cin >> M >> N; 

    for(int i=0;i<=N+1;i++){
        for(int j=0;j<=M+1;j++){
            tmt[i][j]=-1;
        }
    }
    
    memset(day, 0, sizeof(day));

    for(int i=1;i<=N;i++){
        for(int j=1;j<=M;j++){
            cin >> tmt[i][j];
        }
    }
    

    for(int i=1;i<=N;i++){
        for(int j=1;j<=M;j++){
            if(tmt[i][j]==1){
                Q.push(make_pair(i,j));
            }
        }
    }

    BFS_t();

    int result=0;
    for(int i=1;i<=N;i++){
        for(int j=1;j<=M;j++){
            if(tmt[i][j]==0){
                cout << "-1"<< "\n";
                return 0;
            }
            result=max(result,day[i][j]);            
        }
    }

    cout << result << "\n";
    
}
