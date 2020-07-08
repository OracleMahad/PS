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

vector<pair<int,pair<int,string>>> V;
// bool compare(pair<int,string> a, pair<int,string>b){
//     return a.first < b.first;
// }
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    cin >> N;
    for(int i=0;i<N;i++){
        int a;
        string b;
        cin >> a;
        cin >> b;
        V.push_back(pair<int,pair<int,string>>(a,make_pair(i,b)));
    }
    vector<pair<int,pair<int,string>>>::iterator iter;
    sort(V.begin(),V.end());

    for(iter=V.begin();iter!=V.end();iter++){
        cout << iter->first <<" "<< iter->second.second <<'\n';
    }

}