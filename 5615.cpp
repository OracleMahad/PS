#include <iostream>
using namespace std;
#define MAXV  4294967296
//long long int minfact[MAXV];
int main() {
    bool * minfact = new bool[MAXV];
	for (unsigned long int i = 2; i < MAXV ; i++) {
		minfact[i] = true;
	}
	for (unsigned long int i = 2; i*i < MAXV; i++) {
		if (minfact[i] == true) {
			for (long long int j = i*i; j < MAXV; j+=i) {
                minfact[j] = false;
			}
		}
	}
    cout << minfact[MAXV-10];
	/*int T;
	cin >> T;
	int k;
	for (int i = 0; i < T; i++) {
		cin >> k;

	}*/
}