#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <cstring>
#include <vector>
#include <climits>

using namespace std;
int N, M;
int len[1000001];

int max_len=0;

long long get_len(){
    long long left =1;
    long long right=2000000000;
    while(left<=right){
        long long sum = 0;
        long long mid = (left+right)/2;
        for(int i = 0;i<N;i++){
            if(len[i]-mid>0)
                sum += (len[i]-mid);
        }

        if (sum>=M){
            max_len = mid;
            left = mid+1;
        }
        else{
            right=mid-1;
        }
    }
    return max_len;
}


int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    cin >> N >> M;

    for(int i=0;i<N;i++){
        cin >> len[i];
    }
    
    cout << get_len() << "\n";

}
