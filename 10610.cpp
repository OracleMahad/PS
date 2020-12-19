#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <cstring>
#include <string>

using namespace std;

bool compare(int a, int b){
    return a>b;
}

int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    string N;
    int cnt=0;

    cin >> N;
    sort(N.begin(),N.end(), compare);
    for(int i=0;i<N.size();i++){
        cnt= (cnt+(int)N.at(i)-21)%3;
    }
    if(N.back()=='0'&&cnt==0){
        cout << N;
    } else {
        cout << -1;
    }
        
}
