#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <cstring>
#include <vector>
#include <climits>

using namespace std;
int N;
long long answer;
int v[500005];
int t[500005];

void merge_sort(int start, int end){
    if(start==end) return;
    int mid = (start + end)/2;

    merge_sort(start, mid);
    merge_sort(mid+1, end);
    int idx = start;
    int i = start;
    int j = mid+1;
    while(i<=mid || j<=end){
        if(i > mid){
            t[idx++]=v[j++];

        } else if(j > end){
            t[idx++]=v[i++];
        } else if(v[i]<=v[j]){
            t[idx++]=v[i++];
        } else {
            t[idx++]=v[j++];
            answer += (mid + 1 - i);
        }
    }
    for(i=start;i<=end;i++){
        v[i]=t[i];
    }  

}

int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    cin >> N;
    for(int i=0;i<N;i++){
        cin >> v[i];
    }

    answer=0;
    merge_sort(0,N-1);
    cout << answer;
}
