#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <cstring>
#include <climits>


using namespace std;
int N;
int D[10001];
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int ans =0;
    cin >> N;
    for(int i=0;i<N;i++){
        cin >> D[i];
    }
    sort(D, D+N);
    for(int i=0;i<N;i++){
        if(D[i]<=0 && D[i+1]<=0 && i+1 < N){
            ans += D[i]*D[i+1];
            i++;
        } else if(D[i]==1 ||(N-i)%2==1){
            ans += D[i];
        } else if(D[i] > 1 && D[i+1] > 1){
            ans += D[i]*D[i+1];
            i++;
        } else {
            ans += D[i];
        }
        
    }


   cout << ans;
}
