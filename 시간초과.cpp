#include <iostream>
#include <string.h>
using namespace std;
void answer(int Y, int [][1001], int* arrD, int sum, int &max_v);
int arrD[1001];
int mat[1001][1001];
int main() {
	int T;
	cin >> T;
	int N, K;
	int X, Y;
	int W;
	int sum, max_v;
	for (int i = 0; i < T; i++) {
		sum = 0;
		max_v = -1;
		for (int j = 0; j < 1001; j++) {
			arrD[j] = 0;
		}
		for (int j = 0; j < 1001; j++) {
			for (int k = 0; k < 1001; k++) {
				mat[j][k] = 0;
			}
		}
		cin >> N >> K;

		for (int j = 1; j < N + 1; j++) {
			cin >> arrD[j];
		}
		for (int j = 0; j < K; j++) {
			cin >> X >> Y;
			mat[X][Y] = 1;
		}
		cin >> W;
		answer(W, mat, arrD, sum, max_v);
		cout << max_v << endl;
	}
}

void answer(int Y, int mat[][1001], int* arrD, int sum, int &max_v) {
	int count = 0;
	sum += arrD[Y];
	for (int i = 0; i < 1002; i++) {
		if (mat[i][Y] == 1) {
			count++;
			answer(i, mat, arrD, sum, max_v);
		}
	}
	if (count == 0)
		if (max_v == -1 || max_v < sum)
			max_v = sum;
}