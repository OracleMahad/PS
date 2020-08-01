#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <string>
#include <list>
#include <vector>
using namespace std;
void get(int N){
    if(N==0)
        return ;
    if(N%(-2)==0){
        get(N/(-2));
        cout << "0";
    }
    else{
        get((N-1)/(-2));
        cout << "1";
    } 
}
int main(){
    int N;
    cin >> N;
    if(N==0)
        cout<< N;
    else    
        get(N);
}