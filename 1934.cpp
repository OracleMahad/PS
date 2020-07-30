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
    int A, B, C, T;
    cin >> T;
    while(T--){
        cin >> A >> B;
        C= gcd(A,B);
        cout << A*B/C<<"\n";
    }

}