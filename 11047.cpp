#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <cstring>
#include <vector>
#include <climits>

using namespace std;
int N, K;
int price[11];

int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    int cnt = 0;
    cin >> N >> K;

    for(int i = 1 ; i <= N; i++){
        cin >> price[i];
    }

    int idx = N;
    while(K!=0&&idx!=0){
        if(price[idx]<=K){
            K-=price[idx];
            cnt++;
        } else {
            idx--;
        }
    }
    cout << cnt ;
}
