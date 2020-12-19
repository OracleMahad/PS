#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <cstring>
#include <vector>
#include <climits>

using namespace std;
int N;
int answer;
vector <pair<int, int>> v;


int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    answer = 0;
    cin >> N;
    for(int i=0;i<N;i++){
        int n;
        cin >> n;
        v.push_back(make_pair(n, i));
    }
    sort(v.begin(), v.end());
    
    for(int i=0;i<N;i++){
        answer = max(answer, v[i].second - i);
    }
    
    cout << answer;
}
