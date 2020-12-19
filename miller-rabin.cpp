#include <iostream>
using namespace std;
long long int  ipow(long long int b, long long int e, long long int mod){
    long long int ret = 1;
    b%=mod;
    while(e){
        if(e&1){
            ret*=b;
            ret%=mod;
        }  
        (b*=b)%= mod;
        e >>=1;
    }
    return ret;
}
bool miller_counter(long long int n, long long int a){
    if(a%n==0)
        return 0;
    for(long long int e=n-1;;){
        long long int tmp = ipow(a,e,n);
        if(tmp == n-1) return 0;
        if(e&1){return tmp != 1;}
        e >>=1;
    }
}
int miller_base[]={2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37};

bool isprime(long long int x){
    
    for (int i=0 ;i<12;i++)
        if(miller_counter(x,miller_base[i]))
            return 0;
    return 1;
}
int main(){
    int T;
    int count=0;
    cin >> T;
    for(int i=0;i<T;i++)
    {
        long long int input;
        cin >> input;
        count+=isprime(2*input+1);
    }
    cout << count;

}
//틀림ㅋㅋㅋㅋㅋㅋㅋㅋㅋㅋ