#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <string>
#include <list>
#include <vector>
#include <cmath>
using namespace std;
int A, B, m;
void get(long N){
    if(N==0)return;
    get(N/(long)B);
    cout << N%(long)B << " ";
}
int main(){
    
    int S;
    long dec =0;
    cin >> A >> B;
    cin >> m;
    for(int i=m-1;i>=0;i--){
        cin >> S;
        dec=dec+(long)S*pow(A,i);
    }
    if(dec==0)
        cout << "0";
    else
        get(dec);
}