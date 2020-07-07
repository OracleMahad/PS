#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <limits.h>
#include <cstring>
#include <vector>
#include <string>
using namespace std;
int N;
int S[1000000];
int SS[1000000];

void merging(int low, int high){
    int mid=(low+high)/2;
    int i=low;
    int j=mid+1;
    int k=low;
    while(i<=mid&&j<=high){
        if(S[i]<=S[j])
            SS[k++]=S[i++];
        else
            SS[k++]=S[j++];
    }
    while(i<=mid){
        SS[k++]=S[i++];
    }
    while(j<=high){
        SS[k++]=S[j++];
    }
    for(int index=low;index<=high;index++){
        S[index]=SS[index];
    }

}

void mergesort(int low, int high){
    if(high<=low)return;
    int mid=(low+high)/2;
    mergesort(low, mid);
    mergesort(mid+1, high);
    merging(low,high);
}

int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    cin >> N;
    for(int i=0;i<N;i++){
        cin >> S[i];
    }

    mergesort(0,N-1);

    for(int i=0;i<N;i++){
        cout << S[i] << '\n';
    }

}