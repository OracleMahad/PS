#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <cstring>
#include <vector>
#include <climits>

using namespace std;
int N, C;
int house[200000];
int max_len;
int get_len(){
    long long left=1;
    long long right =100000000;
    while(left <= right){
        long long mid=(left+right)/2;
        int low_index = 0;
        int num = 0;
        for(int i=1;i<N;i++){
            if(mid<=(house[i]-house[low_index])){
                num++;
                low_index=i;
                cout<< low_index << endl;
            }
        }
        cout << left<<" "<<right<<" "<< num << " " << mid << endl;;
        if(C<num){
            left=mid+1;
        }
        else if(C==num){
            max_len=mid;
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

    cin >> N >> C;

    for(int i=0;i<N;i++){
        cin >> house[i];
    }
    sort(house, house+N);
    cout << get_len() << "\n";

}
