#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <string>
#include <list>
#include <vector>
using namespace std;

int main(){
    string N;
    int B=2;
    int result = 0;
    int radix = 1;
    cin >> N;
    int i=0;
    if(N.length()%3==1){
        cout << (int)(N[0]-48);
        i=1;
    }
    if(N.length()%3==2){
        cout << (int)(N[0]-48)*2+(int)(N[1]-48);
        i=2; 
    }
    while(i<N.length()){
        cout <<  (int)(N[i]-48)*4+(int)(N[i+1]-48)*2+(int)(N[i+2]-48);
        i=i+3;
    }
    
}