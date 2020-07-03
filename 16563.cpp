#include <iostream>
using namespace std;
int minfact[5000001];
void solve(int k){
	while (k != 1) {
		cout << minfact[k] << " ";
		k = k / minfact[k];
	}
	cout << endl;
}
int main() {
	minfact[0] =minfact[1]=-1;
	for (int i = 2; i < 5000001; i++) {
		minfact[i] = i;
	}
	for (int i = 2; i*i < 5000001; i++) {
		if (minfact[i] == i) {
			for (int j = i*i; j < 5000001; j+=i) {
				if (minfact[j] == j) {
					minfact[j] = i;
				}
			}
		}
	}
	int T;
	cin >> T;
	int k;
	for (int i = 0; i < T; i++) {
		cin >> k;
		solve(k);
	}
}