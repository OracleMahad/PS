#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <cstring>
#include <list>
#include <vector>
#include <cmath>
using namespace std;
int n;
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    
    cin >> n ;
    int N = n;
    int div=2;
    while(N!=1&&div<=n){
        if(N%div==0){
            cout << div <<"\n";
            N/=div;
        }
        else
            div++;
    }
   
}