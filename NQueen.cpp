#include <iostream>
#include <cstdlib>
using namespace std;
int col[100000];
int n;
bool promising(int i){
    bool switching= true;
    int k=1;
    while(k<i&&switching){
        if(col[i]==col[k]||abs(col[i]-col[k])==i-k)
            switching = false;
        k++;
    }
    return switching;
}
void queens(int i){
    if(promising(i)){
        if (i==n){
            for(int k=1;k<=n;k++){
                cout << col[k] <<endl;
            }
        }
        else
        {
            for(int j=1;j<=n;j++)
            {
                col[i+1]=j;
                queens(i+1);
            }
        }
        
    }
}
int main() {
	cin >> n;
	queens(0);
}