#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <cstring>
#include <vector>
#include <climits>

using namespace std;
int N;
char mat[6160][3080];

void star_fractal(int idx, int idy, int num){
    
    if(num==3){
        mat[idx][idy] = '*';

        mat[idx-1][idy+1] = '*';
        mat[idx+1][idy+1] = '*';

        mat[idx-2][idy+2] = '*';
        mat[idx-1][idy+2] = '*';
        mat[idx][idy+2] = '*';
        mat[idx+1][idy+2] = '*';
        mat[idx+2][idy+2] = '*';
        return ;
    }
    
    star_fractal(idx , idy , num/2);
    star_fractal(idx - num/2, idy + num/2, num/2);
    star_fractal(idx + num/2, idy + num/2, num/2);
}

int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    memset(mat, 0 , sizeof(mat));

    cin >> N;

    star_fractal( N, 1, N);

    for(int i = 1 ; i <= N; i++){
        for(int j = 1 ; j <= 2*N; j++){
            if (mat[j][i]==0){
                cout << " ";
            } else {
                cout << "*";
            }
        }
        cout << "\n";
    }
}
