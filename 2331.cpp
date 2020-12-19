#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <cstring>
#include <list>
#include <vector>
#include <queue>
#include <cmath>
using namespace std;
int A, P, result;
vector <int> graph[1000001];

int get_next(int x){
    return (int)(pow(x/100000,P)
                +pow((x%100000)/10000,P)
                +pow((x%10000)/1000,P)
                +pow((x%1000)/100,P)
                +pow((x%100)/10,P)
                +pow((x%10),P));
}

int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    result=0;
    cin >> A >> P;
    int now=A;
    int next;
    while(1){
        next=get_next(now);
        graph[now].push_back(next);
        // cout << next << endl;
        if(graph[now].size()>2)break;
        now=next;
    }

    for(int i=1;i<=1000000;i++){
        if(graph[i].size()==1){
            result++;
        }
    }

    cout << result <<"\n";

}