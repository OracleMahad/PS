#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <cstring>
#include <list>
#include <vector>
#include <cmath>
using namespace std;
int num[1001];
int N, n;
int main(){
    int result =0;
    memset(num,0,sizeof(num));
    cin >> N;
    num[1]=1;
    for(int i=2;i<500;i++){
        for(int j=2;i*j<=1000;j++){
            if(num[i]==0)
                num[i*j]=1;
        }
    }
    for(int i=0; i<N; i++){
        cin >> n;
        if(num[n]==0)
            result++;
    }
    cout << result;
}