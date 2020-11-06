#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <cstring>
#include <climits>


using namespace std;
int R, C;
int mat[1001][1001];
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    cin >> R >> C;
    int min_black=INT_MAX;
    int x, y;
    for(int i=0;i<R;i++){
        for(int j=0;j<C;j++){
            cin >> mat[i][j];
            if(i%2==1 && j%2==1)
                if(mat[i][j]<min_black){
                    min_black= mat[i][j];
                    x=i;
                    y=j;
                }
        }
    }
    
    if(R%2==1){
        for(int i=0;i<R;i++){
            for(int j=0;j<C-1;j++){
                cout  << ((i%2==0) ? "R": "L");
            }
            if(i<R-1)cout << "D";
        }    
    } else if(C%1==1){
        for(int i=0;i<C;i++){
            for(int j=0;j<R-1;j++){
                cout  << ((i%2==0) ? "D": "U");
            }
            if(i<C-1)cout << "R";
        }  
    } else {
        for(int i=0;i<R;i++){
            if(i==x||i==x+1){
                
                j+=2;
            } else {
                for(int j=0;j<C-1;j++){
                    cout  << ((i%2==0) ? "R": "L");
                }
                if(i<R-1)cout << "D";
            }
        }  
    }    

   
}
