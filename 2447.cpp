#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <cstring>
#include <vector>
#include <climits>

using namespace std;
int N;
char mat[2200][2200];

void star_fractal(int idx, int idy, int num){
    
    if(num==1){
        mat[idx][idy] = '*';
        return ;
    }

    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            if(!(i==1&&j==1))
                star_fractal(idx + i*num/3, idy + j*num/3, num/3);
        }
    }
}

int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    memset(mat, 0 , sizeof(mat));

    cin >> N;

    star_fractal( 1, 1, N);

    for(int i = 1 ; i <= N; i++){
        for(int j = 1 ; j <= N; j++){
            if (mat[i][j]==0){
                cout << " ";
            } else {
                cout << "*";
            }
        }
        cout << "\n";
    }
}
