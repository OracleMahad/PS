#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <cstring>
#include <vector>
#include <climits>

using namespace std;
int N, M;
vector <int> v;
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    cin >> N >> M;
    for(int i = 0 ; i < N+M;i++){
        int input;
        cin >> input;
        v.push_back(input);
    }

    sort(v.begin(),v.end());
    for(int i = 0 ; i < N+M ;i++){
        cout << v[i] <<" ";
    }
    
}
