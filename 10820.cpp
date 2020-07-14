#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <limits.h>
#include <cstring>
#include <vector>
#include <string>
using namespace std;
int N;
string order;
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    while(1){
        getline(cin,order);
        if(order.size()==0)break;
        int a=0, A=0, num=0, vac=0;
        for(int i=0;i<order.size();i++){
            if((int)order.at(i)>=97&&(int)order.at(i)<=122){
                a++;
            }
            if((int)order.at(i)>=65&&(int)order.at(i)<=90){
                A++;
            }
            if((int)order.at(i)>=48&&(int)order.at(i)<=57){
                num++;
            }
            if((int)order.at(i)==32){
                vac++;
            }
        }
        if(a+A+num+vac==0)break;
        cout << a <<" "<< A <<" "<< num <<" "<< vac << "\n";
    }
}
