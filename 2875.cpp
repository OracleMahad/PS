#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <cstring>
#include <vector>
#include <climits>

using namespace std;
int N, M, K;

int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int ans = 0;
    cin >> N >> M >> K;

    while(N+M >= K && N >=2 && M >= 1 ){
        N-=2;
        M--;
        ans++;
    }
    cout << ans-1;
}
