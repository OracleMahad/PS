#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <cstring>
#include <list>
#include <vector>
#include <cmath>
using namespace std;
long long  N, M;
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int num2=0;
    int num5=0;
    
    cin >> N;
    cin >> M;

    for(long long i=2;i<=N;i*=2){
        num2+=N/i;
    }
    for(long long i=5;i<=N;i*=5){
        num5+=N/i;
    }

    for(long long i=2;i<=M;i*=2){
        num2-=M/i;
    }
    for(long long i=5;i<=M;i*=5){
        num5-=M/i;
    }

    long long A = N-M;
    for(long long i=2;i<=A;i*=2){
        num2-=A/i;
    }
    for(long long i=5;i<=A;i*=5){
        num5-=A/i;
    }

    cout << min(num2,num5) <<"\n";
   
}



