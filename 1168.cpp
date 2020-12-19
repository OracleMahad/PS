#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <string>
#include <list>
#include <vector>

using namespace std;
int N;
int K;
int I;
int max_size;
vector<int> vec;

int main(){
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    I=-1;
    cin >> N;
    cin >> K;
    for(int i=1;i<=N;i++){
        vec.push_back(i);
    }
    max_size=N;
    cout << "<";

    while(!vec.empty()){
        I=(I+K)%max_size;
        cout << vec.at(I);
        vec.erase(vec.begin()+I);
        I--;
        max_size--;
        if(!vec.empty())
            cout << ", ";
    }

    cout << ">";
}