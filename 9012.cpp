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
    cin >> N;
    for(int i=0;i<N;i++){
        cin >> order;
        int stacksize=0;
        for(int j=0;j<order.size();j++){
            if(order.at(j) == '(' ){
                stacksize++;
            }
            else{
                stacksize--;
            }
            if(stacksize<0)break;
        }
        if(stacksize!=0){
            cout << "NO" << "\n";
        }
        else{
            cout << "YES"<< "\n";
        }

    }
}
