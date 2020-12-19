#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <string>
#include <list>
#include <vector>
using namespace std;
void get(int N, int B){
    if(N==0)
        return ;
    get(N/B,B);
    if(N%B>=10)
        cout<< (char)(N%B+55);
    else
        cout<< N%B;
}
int main(){
    int N,B;
    char A[36];
    cin >> N >> B;
    for(int i=10;i<36;i++){
        A[i]=i+55;
    }
    get(N,B);
}