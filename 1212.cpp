#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <string>
#include <list>
#include <vector>
using namespace std;

int main(){
    string N;

    cin >> N;
    int i=0;
    while(i<N.length()){
        switch ((int)(N[i]-48))
        {
        case 0 :
            if(i==0)
                cout << "0";
            else
                cout << "000";
            break;
        case 1 :
            if(i==0)
                cout << "1";
            else
                cout << "001";
            break;
        case 2 :
            if(i==0)
                cout << "10";
            else
                cout << "010";
            break;
        case 3 :
            if(i==0)
                cout << "11";
            else
                cout << "011";
            break;
        case 4 :
            cout << "100";
            break;
        case 5 :
            cout << "101";
            break;
        case 6 :
            cout << "110";
            break;
        case 7 :
            cout << "111";
            break;
        default:
            break;
        }
        i++;
    }
    
}