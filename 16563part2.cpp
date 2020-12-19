#include <iostream>
#include <vector>
using namespace std;
bool minfact[5000001];
vector<int> prime;
int main() {
	int T;
    
	cin >> T;
	for (int i = 1; i < 5000001; i++) {
		minfact[i] = 1;
	}
	for (int i = 2; i*i < 5000001; i++) {
		if (minfact[i] != 1) {
			continue;
		}
        prime.push_back(i);
		for (int j = i*i; j < 5000001; j+=i) {
			minfact[j] = 0;
		}
	}
	int k;
	for (int i = 0; i < T; i++) {
		cin >> k;
		int index=0;
		while(index<prime.size()||k!=1){
            if(k%prime.at(index)==0){
                cout << prime.at(index) << " ";
                k=k/prime.at(index);
            }
			else{
                index++;
            }
		}
		cout << endl;
	}
}