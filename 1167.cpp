#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <cstring>


using namespace std;
double a, b, c;
double AF, BD, CE;

int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    //Ceva's theorem
    cin >> a >> b >> c;
    cin >> AF >> BD;
    // cout << fixed;
    // cout.precision(10);

    double x;
    x=AF/(c-AF)*BD/(a-BD);
    CE=b/(x+1);
    cout << CE;
}
