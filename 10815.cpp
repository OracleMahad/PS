#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <cstring>
#include <vector>
#include <climits>

using namespace std;
int N, M;
int cardN[500000];
int cardM[500000];
int visit[];

int findM(int x){
    int own=0;
    int left=0;
    int right=N-1;
    while(left <= right){
        int mid=(left+right)/2;
        if(x<cardN[mid]){
            right=mid-1;
        }
        else if(x==cardN[mid]){
            own=1;
            break;
        }
        else{
            left=mid+1;
        }
    }
    return own;
}

int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    cin >> N;
    for(int i=0;i<N;i++){
        cin >> cardN[i];
    }
    sort(cardN,cardN+N);
    cin >> M;
    for(int i=0;i<M;i++){
        cin >> cardM[i];
        cout << findM(cardM[i]) << " ";
    }

    for(int i=0;i<M;i++){
        cin >> cardM[i];
        cout << findM(cardM[i]) << " ";
    }
    
}
