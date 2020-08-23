#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <cstring>
#include <cmath>
using namespace std;
#define SIZE 1000001

int n[SIZE];
int tree [SIZE*4];
int N, M;

int init_tree(int start, int end, int node){
    if(start==end) return tree[node]= n[start];
    int mid = (start+end)/2;
    return tree[node] = min(init_tree(start, mid, node*2), init_tree(mid+1, end, node*2+1));
}

int min_tree(int start, int end, int node, int left, int right){
    if(left > end || right < start) return 1000000001;
    if(left <= start && end <= right ) return tree[node];
    int mid = (start+end)/2;
    return min(min_tree(start, mid, node*2, left, right), min_tree(mid+1, end, node*2+1, left, right));
}

int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    cin >> N >> M;
    for(int i = 0;i<N;i++){
        cin >> n[i];
    }

    init_tree(0,N-1,1);

    for(int i = 0;i<M;i++){
        int a, b;
        cin >> a >> b;
        cout << min_tree(0, N-1 , 1, a-1, b-1) <<"\n";
    }

}