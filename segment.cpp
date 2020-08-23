#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <cstring>
#include <cmath>
using namespace std;
#define SIZE 12

int a[SIZE]= {1, 9, 3, 8, 4, 5, 5, 9, 10, 3, 4, 5};
int tree [SIZE*4];

int init_tree(int start, int end, int node){
    if(start==end) return tree[node]= a[start];
    int mid = (start+end)/2;
    return tree[node] = init_tree(start, mid, node*2) + init_tree(mid+1, end, node*2+1);
}

int sum_tree(int start, int end, int node, int left, int right){
    if(left > end || right < start) return 0;
    if(left <= start && end <= right ) return tree[node];
    int mid = (start+end)/2;
    return sum_tree(start, mid, node*2, left, right) + sum_tree(mid+1, end, node*2+1, left, right);
}

void update(int start, int end, int node, int index, int dif){
    if(index > end || index < start) return ;
    tree[node] += dif;
    if (start == end) return;
    int mid = (start+end)/2;
    update(start, mid, node*2, index, dif);
    update(mid+1, end, node*2+1, index, dif);
}

int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    init_tree(0,11,1);
    cout << sum_tree(0, 11, 1, 0, 12) <<endl;
    update(0, 11 , 1, 5, -5);
    cout << sum_tree(0, 11, 1, 0, 12) <<endl;
    

    
}