#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <cstring>
#include <string>
#include <vector>
#include <climits>


using namespace std;
int N;
vector <pair<int, int>> v;
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int ans=0;
    cin >> N;

    for(int i= 0 ;i<N;i++){
        int a, b;
        cin >> a >>b;
        v.push_back(make_pair(b,a));
    }
    sort(v.begin(), v.end());

    int idx=0;
    int start = 0;
    while(1){
        if(v.at(idx).second >= start){
            ans++;
            start = v.at(idx).first;
        }         
        
        idx++;
        if(idx==N)break;
    }
        
    cout << ans;
}
