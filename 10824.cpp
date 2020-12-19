#include <iostream>
#include <cstdlib>
#include <string>
using namespace std;

int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    string a, b, c, d;
    cin >> a >> b >> c >>d;
    a=a+b;
    c=c+d;
    long long x,y;
    x=atoll(a.c_str());
    y=atoll(c.c_str());

    cout << x+y << "\n";
}
