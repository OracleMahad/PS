#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <string>
#include <list>
#include <vector>
using namespace std;

int main(){
    string N;
    int B;
    int result = 0;
    int radix = 1;
    cin >> N >> B;
    for(int i=N.length()-1;i>=0;i--){
        if(N[i]>=65)
            result += (int)(N[i]-55)*radix;
        else
            result += (int)(N[i]-48)*radix;
        
        radix=radix*B;
    }
    cout << result;
}