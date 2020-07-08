#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <limits.h>
#include <cstring>
#include <vector>
#include <string>
using namespace std;
int N;
int S[10001];
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    memset(S,0,sizeof(S));
    cin >> N;
    for(int i=0;i<N;i++){
        int a;
        cin >> a;
        S[a]++;
    }

    for(int i=1;i<=10000;i++){
        for(int j=0;j<S[i];j++){
            cout<< i <<'\n';
        }
    }

}