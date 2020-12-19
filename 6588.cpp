#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <cstring>
#include <list>
#include <vector>
#include <cmath>
using namespace std;
int num[1000001];
int n;
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
    while(1){
        cin >> n ;
        int count = 0;
        if(n==0)
            break;
        for(int i=3; i<= n/2; i=i+2){
            if(num[i]==0&&num[n-i]==0){
                cout << n << " = " << i << " + " << n-i <<"\n";
                count++;
                break;
            }
        }
        if(count==0)
            cout << "Goldbach's conjecture is wrong.";
    }
   
}