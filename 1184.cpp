#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <limits.h>
#include <cstring>
#include <vector>
using namespace std;
int N;
int revenue[50][50];
int sum[50][50];
vector <int> sum1; 
vector <int> sum2; 
vector <int> sum3;
vector <int> sum4;
void get_reward1(int x, int y){
    for(int i=x;i<N;i++){
        int sumk=0;
        for(int j=y;j>=0;j--){
            sumk+=revenue[i][j];
            if(i==x){
                sum[i][j]=sumk;
                sum1.push_back(sum[i][j]);
            }
            else{
                sum[i][j]=sum[i-1][j]+sumk;
                sum1.push_back(sum[i][j]);
            }
        }
    }
}
void get_reward2(int x, int y){
    for(int i=x;i>=0;i--){
        int sumk=0;
        for(int j=y;j>=0;j--){
            sumk+=revenue[i][j];
            if(i==x){
                sum[i][j]=sumk;
                sum2.push_back(sum[i][j]);
            }
            else{
                sum[i][j]=sum[i+1][j]+sumk;
                sum2.push_back(sum[i][j]);
            }
        }
    }
}
void get_reward3(int x, int y){
    for(int i=x;i>=0;i--){
        int sumk=0;
        for(int j=y;j<N;j++){
            sumk+=revenue[i][j];
            if(i==x){
                sum[i][j]=sumk;
                sum3.push_back(sum[i][j]);
            }
            else{
                sum[i][j]=sum[i+1][j]+sumk;
                sum3.push_back(sum[i][j]);
            }
        }
    }
}
void get_reward4(int x, int y){
    for(int i=x;i<N;i++){
        int sumk=0;
        for(int j=y;j<N;j++){
            sumk+=revenue[i][j];
            if(i==x){
                sum[i][j]=sumk;
                sum4.push_back(sum[i][j]);
            }
            else{
                sum[i][j]=sum[i-1][j]+sumk;
                sum4.push_back(sum[i][j]);
            }
        }
    }
}



int main() {
    int way=0;
    cin >>N;
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            cin >> revenue[i][j];
        }
    }
    for(int i=0;i<N-1;i++){
        for(int j=0;j<N-1;j++){
            get_reward1(i+1,j);
            get_reward3(i,j+1);
            for(int m=0;m<sum1.size();m++){
                for(int n=0;n<sum3.size();n++){
                    if(sum1[m]==sum3[n]){
                        way++;
                        //cout << sum1[m] <<endl;
                    }
                }
            }
            get_reward2(i,j);
            get_reward4(i+1,j+1);
            for(int m=0;m<sum2.size();m++){
                for(int n=0;n<sum4.size();n++){
                    if(sum2[m]==sum4[n]){
                        way++;
                        //cout << sum2[m] <<endl;
                    }
                }
            }
            sum1.clear();
            sum3.clear();
            sum2.clear();
            sum4.clear();

        }
    }
    
    cout << way << endl;     
}