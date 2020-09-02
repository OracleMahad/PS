#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <cstring>
#include <vector>
#include <climits>

using namespace std;
int K, N;
int lan[10001];

long long max_lan=0;

long long get_lan(){
    long long left =1;
    long long right=INT_MAX;
    while(left<=right){
        int sum = 0;
        long long mid = (left+right)/2;
        for(int i = 0;i<K;i++){
            sum += lan[i]/mid;
        }

        if (sum>=N){
            max_lan=mid;
            left=mid+1;


        }
        else{
            right=mid-1;


        }
    }
    return max_lan;
}


int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    cin >> K >> N;

    for(int i=0;i<K;i++){
        cin >> lan[i];
    }
    
    cout << get_lan() << "\n";

}
