#include <iostream>
#include <string.h>
#include <algorithm>
using namespace std;
int arrD[1001];

int main() {
	memset(arrD,1,sizeof(arrD));	
	for (int j = 0; j <100; j++) {
		cout << arrD[j];
	}
}