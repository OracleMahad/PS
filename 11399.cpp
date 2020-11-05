#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <cstring>


using namespace std;
int N;
int P[1001];
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int ans=0;
    cin >> N;

    for(int i= 0 ;i<N;i++){
        cin >> P[i];
    }
    sort(P, P+N);
    int sum = 0;
    for(int i= 0 ;i<N;i++){
        ans = ans + sum + P[i];
        sum = sum + P[i];
    }
        
    cout << ans;
}
