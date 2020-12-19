#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <cstring>
#include <vector>
#include <climits>

using namespace std;
int N, K = 0;
vector <pair<int, int>> v;
void hanoi(int from, int to, int by, int n){
    K++;
    if(n==1){
        v.push_back(make_pair(from, to));
        return;
    }
    hanoi(from, by, to, n-1);
    v.push_back(make_pair(from, to));
    hanoi(by, to, from , n-1);
}

int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    cin >> N;

    hanoi( 1, 3, 2, N);
    cout << K << "\n";

    vector <pair<int, int>> ::iterator iter;

    for(iter=v.begin();iter!=v.end();iter++){
        cout << iter->first << " " << iter -> second << "\n";
    }
    
}
