#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <cstring>

using namespace std;
int N;
int tree[27][2];

void preorder(int start){
    if(start==-1)return;

    cout << (char)(start+65);
    preorder(tree[start][0]);
    preorder(tree[start][1]);
}
void inorder(int start){
    if(start==-1)return;

    inorder(tree[start][0]);
    cout << (char)(start+65);
    inorder(tree[start][1]);
}
void postorder(int start){
    if(start==-1)return;

    postorder(tree[start][0]);
    postorder(tree[start][1]);
    cout << (char)(start+65);

}

int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    cin >> N; 
    for(int i=0;i<N;i++){
        char a, b, c;
        cin >> a >> b >> c;
        if(b=='.'){
            tree[(int)(a-65)][0]=-1;
        }
        else{
            tree[(int)(a-65)][0]=(int)(b-65);
        }
        if(c=='.'){
            tree[(int)(a-65)][1]=-1;
        }
        else{
            tree[(int)(a-65)][1]=(int)(c-65);
        }
    }
    preorder(0);
    cout << "\n";
    inorder(0);
    cout << "\n";
    postorder(0);
    cout << "\n";

}
