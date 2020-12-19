#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <string>
#include <list>
#include <vector>
using namespace std;
long long gcd(long long m,long long n){
    long long k;
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
    long long A, B, C;
    cin >> A >> B;
    C= gcd(A,B);
    for(int i=0;i<C;i++){
        cout <<"1";
    }
    cout << "\n";
}