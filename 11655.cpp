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
    getline(cin,order);
    for(int i=0;i<order.size();i++){
        if(order.at(i)>='a' && order.at(i)<='m'){
            order[i]=(order.at(i)+13);

        }
        else if(order.at(i)>='n' && order.at(i)<='z'){
            order[i]=(order.at(i)-13);


        }
        else if(order.at(i)>=65 && order.at(i)<=77){
            order[i]=(order.at(i)+13);

        }
        else if(order.at(i)>=78 && order.at(i)<=90){
            order[i]=(order.at(i)-13);
        }
    }
    std::cout << order << "\n";
}
