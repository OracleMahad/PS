#include <iostream>
#include <vector>
using namespace std;
int  A;
int answer4(int a,int b, int c, int d, int e);
int answer3(int a,int b, int c, int e);
int answer2(int a, int b, int e);
int main() {
    int n[5];
    bool go=true;
    while(1){
        for(int i=0;i<5;i++){
            cin >> n[i];
            if(n[i]<0){
                go=false;
                break;
            }
            cout << n[i] <<" ";
        }
        if(go==0)
            break;
        if((answer4(n[0],n[1],n[2],n[3],n[4]))||(answer4(n[0],n[1],n[3],n[2],n[4]))||(answer4(n[0],n[2],n[1],n[3],n[4]))||(answer4(n[0],n[2],n[3],n[1],n[4]))||(answer4(n[0],n[3],n[1],n[2],n[4]))||(answer4(n[0],n[3],n[2],n[1],n[4]))
        ||(answer4(n[1],n[0],n[2],n[3],n[4]))||(answer4(n[1],n[0],n[3],n[2],n[4]))||(answer4(n[1],n[2],n[0],n[3],n[4]))||(answer4(n[1],n[2],n[3],n[0],n[4]))||(answer4(n[1],n[3],n[0],n[2],n[4]))||(answer4(n[1],n[3],n[2],n[0],n[4]))
        ||(answer4(n[2],n[0],n[1],n[3],n[4]))||(answer4(n[2],n[0],n[3],n[1],n[4]))||(answer4(n[2],n[1],n[0],n[3],n[4]))||(answer4(n[2],n[1],n[3],n[0],n[4]))||(answer4(n[2],n[3],n[0],n[1],n[4]))||(answer4(n[2],n[3],n[1],n[0],n[4]))
        ||(answer4(n[3],n[0],n[1],n[2],n[4]))||(answer4(n[3],n[0],n[2],n[1],n[4]))||(answer4(n[3],n[1],n[0],n[2],n[4]))||(answer4(n[3],n[1],n[2],n[0],n[4]))||(answer4(n[3],n[2],n[0],n[1],n[4]))||(answer4(n[3],n[2],n[1],n[0],n[4]))
        )
            cout <<"OK!" <<endl;
        else
        {
            cout << "NO!"<<endl;
        }
        
    }
}
int answer4(int a,int b, int c, int d, int e){
    if(answer3( a+b, c, d, e))return 1;
    if(answer3( a-b, c, d, e))return 1;
    //if(answer3( b-a, c, d, e))return 1;
    if(answer3( a*b, c, d, e))return 1;
    if(b)
        if(answer3( a/b, c, d, e))return 1;
    /*if(a)
        if(answer3( b/a, c, d, e))return 1;*/
    if(answer3( a, b+c, d, e))return 1;
    if(answer3( a, b-c, d, e))return 1;
    //if(answer3( a, c-b, d, e))return 1;
    if(answer3( a, b*c, d, e))return 1;
    if(c)
        if(answer3( a, b/c, d, e))return 1;
    /*if(b)
        if(answer3( a, c/b, d, e))return 1;*/
    if(answer3( a, b, c+d, e))return 1;
    if(answer3( a, b, c-d, e))return 1;
    //if(answer3( a, b, d-c, e))return 1;
    if(answer3( a, b, c*d, e))return 1;
    if(d)
        if(answer3( a, b, c/d, e))return 1;
    /*if(c)
        if(answer3( a, b, d/c, e))return 1;*/
    return 0;
}
int answer3(int a,int b, int c, int e){
    if(answer2( a+b, c, e))return 1;
    if(answer2( a-b, c, e))return 1;
    //if(answer2( b-a, c, e))return 1;
    if(answer2( a*b, c, e))return 1;
    if(b)
        if(answer2( a/b, c, e))return 1;
    /*if(a)
        if(answer2( b/a, c, e))return 1;*/
    if(answer2( a, b+c, e))return 1;
    if(answer2( a, b-c, e))return 1;
    //if(answer2( a, c-b, e))return 1;
    if(answer2( a, b*c, e))return 1;
    if(c)
        if(answer2( a, b/c, e))return 1;
    /*if(b)
        if(answer2( a, c/b, e))return 1;*/
    return 0;
}
int answer2(int a, int b, int e){
    if(a+b==e||a-b==e||a*b==e||b-a==e){
        //cout <<"OK" <<endl;
        return 1;
    }
    if(b){
        if(a/b==e){
            //cout <<"OK" <<endl;
            return 1;
        }
    }
    if(a){
        if(b/a==e){
            //cout <<"OK" <<endl;
            return 1;
        }
    }
    return 0;
}