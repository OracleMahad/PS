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

vector<pair<pair<int,int>,pair<int,string>>> V;
bool compare(pair<pair<int,int>,pair<int,string>> a, pair<pair<int,int>,pair<int,string>>b){
    if(a.first.first==b.first.first&&a.first.second==b.first.second&&a.second.first==b.second.first)
        return a.second.second<b.second.second;
    if(a.first.first==b.first.first&&a.first.second==b.first.second)
        return a.second.first>b.second.first;
    if(a.first.first==b.first.first)
        return a.first.second<b.first.second;
    return  a.first.first>b.first.first;
}
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    cin >> N;
    for(int i=0;i<N;i++){
        int a,b,c;
        string name;
        cin >> name;
        cin >> a;
        cin >> b;
        cin >> c;
        V.push_back(pair<pair<int,int>,pair<int,string>>(make_pair(a,b),make_pair(c,name)));
    }
    vector<pair<pair<int,int>,pair<int,string>>>::iterator iter;
    sort(V.begin(),V.end(),compare);

    for(iter=V.begin();iter!=V.end();iter++){
        cout << iter->second.second <<'\n';
    }

}