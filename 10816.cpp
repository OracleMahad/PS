#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <cstring>
#include <vector>
#include <climits>

using namespace std;
int N, M;
int card[20000002];
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    memset(card,0,sizeof(card));
    cin >> N;
    for(int i=0;i<N;i++){
        int input;
        cin >> input;
        card[input+10000000]++;
    }

    cin >> M;
    for(int i=0;i<M;i++){
        int input;
        cin >> input;
        cout << card[input+10000000] << " ";
    }


    
}
