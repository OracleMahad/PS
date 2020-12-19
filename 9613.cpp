#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <string>
#include <list>
#include <vector>
using namespace std;
int gcd(int m,int n){
    int k;
    if(m<n)
        swap(m,n);
    while(n!=0){
        k=m%n;
        m=n;
        n=k;
    }
    return m;
}
int main(){
    int T,N;
    long long result;
    int num[101];
    cin >> T;
    for(int i=0;i<T;i++){
        result=0;
        cin >> N;
        for(int j=1;j<=N;j++){
            cin >> num[j];
        }
        for(int j=1;j<=N;j++){
            for(int k=j+1;k<=N;k++){
                result+=(long long)gcd(num[j],num[k]);
            }
        }

        cout << result <<"\n";
    }
}