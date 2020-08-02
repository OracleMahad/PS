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
    long long result=1;
    for(int i=2;i<=n;i++){
        result*=i;
    }
    cout << result <<"\n";
   
}