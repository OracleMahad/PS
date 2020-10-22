#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <cstring>
#include <vector>
#include <climits>

using namespace std;
int N;
char mat[70][70];

void quadTree(int idx, int idy, int num){
    char x = mat[idy][idx];
    int count = 0;
    for(int i = idx ; i < idx + num ; i++){
        for(int j = idy ; j < idy + num; j++){
            if(x != mat[j][i]) count++;
        }
    }

    if(count == 0){
        cout << x;
    } else if(num/2){
        cout << "(";
        for(int i = idx ; i < idx + num ; i = i + num/2){
            for(int j = idy ; j < idy + num; j = j + num/2){
                quadTree(i , j , num/2);
            }
        }
        cout << ")";
    }
}

int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    cin >> N;
    for(int i = 1 ; i <= N; i++){
        for(int j = 1 ; j <= N; j++){
            cin >> mat[j][i];
        }
    }
    quadTree( 1, 1, N);
}
