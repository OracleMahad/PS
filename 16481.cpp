#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <cstring>


using namespace std;
int r1, r2 ,r3;


int main(){
    // cin.tie(NULL);
    // ios_base::sync_with_stdio(false);

    cin >> r1 >> r2 >> r3;
    // cout << fixed;
    cout.precision(10);
    double r;
    r=1/(1/(double)r1 + (double)1/r2 + (double)1/r3);
    cout << r;
    // printf("%lf",r);
}
