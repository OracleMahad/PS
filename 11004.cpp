#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <limits.h>
#include <cstring>
#include <vector>
#include <string>
using namespace std;
int N;
int S[5000001];
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    memset(S,0,sizeof(S));
    int K;
    cin >> N;
    cin >> K;
    for(int i=0;i<N;i++){
        cin >> S[i];
    }
    sort(S, S+N);

    cout << S[K-1] << "\n";
}