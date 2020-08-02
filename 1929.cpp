#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <cstring>
#include <list>
#include <vector>
#include <cmath>
using namespace std;
int num[1000001];
int a, b;
int main(){
    memset(num,0,sizeof(num));
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    num[1]=1;
    for(int i=2;i<=sqrt(1000000);i++){
        for(int j=2;i*j<=1000000;j++){
            if(num[i]==0)
                num[i*j]=1;
        }
    }
    cin >> a >> b ;
    for(int i=a; i<=b; i++){
        if(num[i]==0)
            cout << i << "\n";
    }
}