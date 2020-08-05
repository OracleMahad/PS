#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <cstring>
#include <list>
#include <vector>
#include <cmath>
using namespace std;
int N, M;
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int num2=0;
    int num5=0;
    
    cin >> N;
    cin >> M;

    for(int i=N-M+1;i<=N;i++){
        int I=i;
        int count=1;
        while(count > 0){
            count=0;
            if(I%2==0){
                I/=2;
                num2++;
                count++;
            }
            if(I%5==0){
                I/=5;
                num5++;
                count++;
            }
        }
    }
    for(int i=2;i<=M;i++){
        int I=i;
        int count=1;
        while(count > 0){
            count=0;
            if(I%2==0){
                I/=2;
                num2--;
                count++;
            }
            if(I%5==0){
                I/=5;
                num5--;
                count++;
            }
        }
    }
    cout << min(num2,num5) <<"\n";
   
}