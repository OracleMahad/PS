#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <cstring>


using namespace std;
long long R, r;



int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    cin >> R >> r;
    //d^2=R(R-2r)
    long long d2=R*(R-2*r);
    cout << d2;
    
}
