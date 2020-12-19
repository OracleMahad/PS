#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <cstring>
using namespace std;

int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int N, M;
    cin >> N >> M;
    if(N==1){
        cout << 1; 
    } else if(N==2){
        cout << min((M+1)/2,4);
    } else if(M<7){
        cout << min(M,4);
    }else {
        cout << M-2;
    }
    
}
