#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <cstring>
#include <vector>
#include <climits>

using namespace std;
int N;
int island[102][102];
int cell[102][102];
int len=INT_MAX;
vector <pair <int, int>> V;

void DFS(int a, int b, int num){
        island[a][b]=num;
        V.push_back(make_pair(a,b));
        if(island[a+1][b]==1){
            island[a+1][b]=num;
            DFS(a+1,b,num);
        }
        if(island[a-1][b]==1){
            island[a-1][b]=num;
            DFS(a-1,b,num);
        }
        if(island[a][b+1]==1){
            island[a][b+1]=num;
            DFS(a,b+1,num);
        }
        if(island[a][b-1]==1){
            island[a][b-1]=num;
            DFS(a,b-1,num);
        }
}
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    cin >> N; 

    memset(cell, 0, sizeof(cell));
    memset(island, -1, sizeof(island));

    for(int i=1;i<=N;i++){
        for(int j=1;j<=N;j++){
            cin >> island[i][j];
        }
    }

    int num=1;    
    for(int i=1;i<=N;i++){
        for(int j=1;j<=N;j++){
            if(island[i][j]==1){
                num++;
                DFS(i,j,num);
            }
        }
    }
    vector <pair <int, int>>::iterator iter1;
    vector <pair <int, int>>::iterator iter2;
    for(iter1=V.begin();iter1!=V.end();iter1++){
        for(iter2=V.begin();iter2!=iter1;iter2++){
            if(island[iter1->first][iter1->second]!=island[iter2->first][iter2->second]){
                len=min(len,abs(iter1->first-iter2->first)+abs(iter1->second-iter2->second)-1);
            }
        }
    }
    

    cout << len << "\n";
    
}
