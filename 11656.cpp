#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <limits.h>
#include <cstring>
#include <vector>
#include <string>
using namespace std;
vector <string> v;
string order;
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    getline(cin,order);

    for(int i=0;i<order.size();i++){
        v.push_back(order.substr(i));
    }

    sort(v.begin(), v.end());
    vector<string>::iterator iter;
    for(iter=v.begin();iter!=v.end();iter++){
        cout << * iter <<"\n";
    }
}
