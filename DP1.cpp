#include <iostream>
#include <string.h>
using namespace std;
int answer(int Y);
int mxv[1001];
int arrD[1001];
int mat[1001][1001];
int main() {
	int T;
	cin >> T;
	int N, K;
	int X, Y;
	int W;

	for (int i = 0; i < T; i++) {
		memset(arrD,0,sizeof(arrD));	
		for (int j = 0; j < 1001; j++) {
			mxv[j] = -1;
		}
		memset(mat,0,sizeof(mat));
		cin >> N >> K;

		for (int j = 1; j < N + 1; j++) {
			cin >> arrD[j];
		}
		for (int j = 0; j < K; j++) {
			cin >> X >> Y;
			mat[X][Y] = 1;
		}
		cin >> W;
		cout << answer(W)<< endl;
	}
}

int answer(int Y) {
	if (mxv[Y]!=-1)
		return  mxv[Y];
	else
	{
		int mx=0;
		for(int i=0;i<1001;i++){
			if(mat[i][Y]==1)
				if(mx<answer(i))
					 mx=answer(i);
		}
		mxv[Y]=mx+arrD[Y];
		return mxv[Y];
	}
}