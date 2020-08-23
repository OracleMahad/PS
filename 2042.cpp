#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <cstring>
#include <cmath>
using namespace std;
#define SIZE 1000001

long long n[SIZE];
long long tree [SIZE*4];
int N, M, K;

long long init_tree(int start, int end, int node){
    if(start==end) return tree[node]= n[start];
    int mid = (start+end)/2;
    return tree[node] = init_tree(start, mid, node*2) + init_tree(mid+1, end, node*2+1);
}

long long sum_tree(int start, int end, int node, int left, int right){
    if(left > end || right < start) return 0;
    if(left <= start && end <= right ) return tree[node];
    int mid = (start+end)/2;
    return sum_tree(start, mid, node*2, left, right) + sum_tree(mid+1, end, node*2+1, left, right);
}

void update(int start, int end, int node, int index, long long dif){
    if(index > end || index < start) return ;
    tree[node] += dif;
    if (start == end) {
        n[start]= tree[node];
        return;
    }
    int mid = (start+end)/2;
    update(start, mid, node*2, index, dif);
    update(mid+1, end, node*2+1, index, dif);
}

int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    cin >> N >> M >> K;
    for(int i = 0;i<N;i++){
        cin >> n[i];
    }

    init_tree(0,N-1,1);

    for(int i = 0;i<M+K;i++){
        int a, b;
        long long c;
        cin >> a >> b >> c;
        if(a==1){
            update(0, N-1 , 1, b-1, (c-n[b-1]));
        }

        if(a==2){
            cout << sum_tree(0, N-1 , 1, b-1, c-1) <<"\n";
        }
    }


    
}