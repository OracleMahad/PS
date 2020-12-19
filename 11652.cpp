#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <limits.h>
#include <cstring>
#include <vector>
#include <string>
using namespace std;
int N;
long long int S[100001];
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    memset(S,0,sizeof(S));
    cin >> N;
    for(int i=0;i<N;i++){
        cin >> S[i];
    }
    sort(S, S+N);
    int result = 0;
    int countsame=1;
    int maxL=1;

    for(int i=1;i<N;i++){
        if(S[i]==S[i-1]){
            countsame++;
            if(maxL<countsame){
                maxL=countsame;
                result=i;
            }
        }
        else{
            countsame=1;
        }
    }
    cout << S[result] << "\n";
}