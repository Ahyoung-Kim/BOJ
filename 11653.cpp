#include<iostream>
#include<cstdlib>
#include<cstring>
#include<string>
#include<cmath>

using namespace std;

int main(void) {
	int N;
	int k = 2;

	cin >> N;

	while (N > 1) {
		if (N % k == 0) {
			cout << k << endl;
			N /= k;
		}
		else {
			k++;
		}
	}

	return 0;
}