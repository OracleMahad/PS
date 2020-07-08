#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <limits.h>
#include <cstring>
#include <vector>
#include <string>
#include <utility>//pair
using namespace std;
int N;

vector<pair<int,int>> V;

int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    cin >> N;
    for(int i=0;i<N;i++){
        int a, b;
        cin >> a;
        cin >> b;
        V.push_back(pair<int,int>(b,a));
    }
    vector<pair<int,int>>::iterator iter;
    sort(V.begin(),V.end());

    for(iter=V.begin();iter!=V.end();iter++){
        cout << iter->second <<" "<< iter->first <<'\n';
    }

}