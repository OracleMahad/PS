#include<iostream>
#include<string.h>
#include<queue>
using namespace std;
int arrD[1001];
int mxv[1001];
int mat[1001][1001];
int main() {
	int T;
	cin >> T;
	int N, K;
	int X, Y;
	int W;
	int max_v;
    queue <int> q;
	for (int i = 0; i < T; i++) {
		memset(arrD,0,sizeof(arrD));
        memset(mat,0,sizeof(mat));
        memset(mxv,0,sizeof(mxv));
		cin >> N >> K;
		max_v=0;
		for (int j = 1; j < N + 1; j++) {
			cin >> arrD[j];
		}
		for (int j = 0; j < K; j++) {
			cin >> X >> Y;
			mat[X][Y] = 1;
		}
		cin >> W;
        q.push(W);
		mxv[W]+=arrD[W];
        while(!q.empty()){
            int c= q.front();
            q.pop();
            for (int k = 0; k < 1001; k++) {
		        if (mat[k][c] == 1) {
                    q.push(k);
					if(mxv[k]<arrD[k]+mxv[c])
						mxv[k]=arrD[k]+mxv[c];
						if(max_v<mxv[k])
							max_v=mxv[k];
                }
			}
        }
		cout << max_v << endl;
	}
}