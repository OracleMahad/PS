#include<iostream>
#include<string.h>
#include<queue>
using namespace std;
int arrD[1001];
int mxv[1001];
int sta[1001];
int mat[1001][1001];
int main() {
	int T;
	cin >> T;
	int N, K;
	int X, Y;
	int W;
	int max_v;
    queue <int> q;
	queue <int> qq;
	for (int i = 0; i < T; i++) {
		for(int j=0;j<1001;j++){
			arrD[j]=-1;
		}		
		for(int j=0;j<1001;j++){
			mxv[j]=-1;
		}		
        memset(mat,0,sizeof(mat));
		memset(sta,0,sizeof(sta));
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
		mxv[W]=arrD[W];
		while(1){
			while(!q.empty()){
				int c= q.front();
				q.pop();
				for (int k = 0; k < 1001; k++) {
					if (mat[k][c] == 1) {
						qq.push(k);
						if(mxv[k]<arrD[k]+mxv[c])
							mxv[k]=arrD[k]+mxv[c];
					}
				}
			}
			if(qq.empty())
				break;
			while(!qq.empty()){
				sta[qq.front()]=1;
				qq.pop();
			}
			for(int j=1;j<1001;j++){
				if(sta[j]==1)
					q.push(j);
			}
			memset(sta,0,sizeof(sta));
		}
		for(int j=1;j<1001;j++){
			if(max_v<mxv[j])
				max_v=mxv[j];
		}
		cout << max_v << endl;
	}
}