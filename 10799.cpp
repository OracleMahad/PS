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
vector<int> v;
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    int result=0;
    cin >> order;
    int stacksize=0;
    int stick=0;
    for(int j=0;j<order.size();j++){
        if(order.at(j) == '(' ){
            if(order.at(j+1)==')'){
                result+=stacksize;
                j++;
            }
            else{
                stacksize++;
                stick++;
            }
        }
        else{
            stacksize--;
        }
    }

    cout << result+ stick << "\n";
    
}
