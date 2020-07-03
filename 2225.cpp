#include <iostream>
using namespace std;
long long DP[201][201];
int main() {
	for (int i = 0; i < 201; i++)
		for (int j = 0; j < 201; j++)
			DP[i][j] = 0;
	for (int i = 0; i < 201; i++)
		DP[1][i] = 1;
	int N, K;
	cin >> N;
	cin >> K;
	for (int i = 2; i< 201; i++) {
		for (int j = 0; j < 201; j++) {
			for (int A = 0; A <= j; A++) {
				DP[i][j] = (DP[i][j]+DP[i - 1][A])%1000000000;
			}
		}
	}
	cout << DP[K][N];
}