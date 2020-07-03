#include <iostream>
using namespace std;
int main() {
	int N;
	cin >> N;
	char* NN = new char[N*N];
	for (int i = 0; i < N*N; i++) {
		cin >> NN[i];
	}
	if (N == 1 || N == 2) {
		cout << "0";
		return 0;
	}
	else if (N == 3) {
		cout << NN[0];
		return 0;
	}
    else if (N==4){
        cout << NN[0]+NN[N-1]+NN[(N-1)*N]+NN[N*N-1]-48*4;
        return 0;
    }
	else {
		int a, b, c, d = 0;
		a = b = c = d;
		for (int i = 0; i < N; i++) {
			a += (int)NN[i];
			a -= 48;
		}
		for (int i = 0; i < N; i++) {
			b += (int)NN[i*N];
			b -= 48;
		}
		for (int i = 0; i < N; i++) {
			c += (int)NN[N*(i + 1) - 1];
			c -= 48;
		}
		for (int i = 0; i < N; i++) {
			d += (int)NN[(N - 1)*(N)+i];
			d -= 48;
		}
		cout << (a+b+c+d)/3-NN[0]-NN[N-1]-NN[(N-1)*N]-NN[N*N-1]+48*4+(N-4)*(N-4);
	}
	delete[] NN;
}