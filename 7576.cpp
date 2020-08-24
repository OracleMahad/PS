#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <cstring>
#include <vector>
#include <string>
#include <queue>
using namespace std;
int M, N;
int tmt[1002][1002];
int day[1002][1002];

queue <pair <int, int>> Q;


void BFS_t(int x, int y){
    pair <int, int> p= make_pair(x,y);
    Q.push(p);

    while(!Q.empty()){
        int a, b;
        a=Q.front().first;
        b=Q.front().second;
        Q.pop();

        if(tmt[a+1][b]==0){
            tmt[a+1][b]=1;
            day[a+1][b]=min(day[a+1][b],day[a][b]+1);
            Q.push(make_pair(a+1,b));
        }
        if(tmt[a-1][b]==0){
            tmt[a-1][b]=1;
            day[a-1][b]=min(day[a-1][b],day[a][b]+1);
            Q.push(make_pair(a-1,b));
        }
        if(tmt[a][b+1]==0){
            tmt[a][b+1]=1;
            day[a][b+1]=min(day[a][b+1],day[a][b]+1);
            Q.push(make_pair(a,b+1));
        }
        if(tmt[a][b-1]==0){
            tmt[a][b-1]=1;
            day[a][b-1]=min(day[a][b-1],day[a][b]+1);
            Q.push(make_pair(a,b-1));
        }
    }
}

int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    memset(tmt, 0, sizeof(tmt));
    memset(day, -1, sizeof(day));


    
    
}
