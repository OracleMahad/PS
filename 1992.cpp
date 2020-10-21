#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <cstring>
#include <vector>
#include <climits>

using namespace std;
int N;
int mat[2200][2200];
int num0 = 0;
int num1 = 0;
int numm1 = 0;
void divide_mat(int idx, int idy, int num){
    int x = mat[idy][idx];
    int count = 0;
    for(int i = idx ; i < idx + num ; i++){
        for(int j = idy ; j < idy + num; j++){
            if(x != mat[j][i]) count++;
        }
    }

    if(count == 0){
        if(x==0) num0++;
        else if(x==1) num1++;
        else numm1++;
    } else if(num/3){
        for(int i = idx ; i < idx + num ; i = i + num/3){
            for(int j = idy ; j < idy + num; j = j + num/3){
                divide_mat(i , j , num/3);
            }
        }
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
    divide_mat( 1, 1, N);

    cout << numm1 << "\n" << num0 << "\n" << num1 <<"\n";
}
