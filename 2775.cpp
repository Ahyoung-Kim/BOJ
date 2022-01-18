#include<iostream>
#include<cstdlib>
#include<cstring>

using namespace std;

int solution(int k, int n) {
	int sol = 0;
	int i;

	if (k == 0) {
		return n;
	}

	for (i = 1; i <= n; i++) {
		sol += solution(k - 1, i);
	}

	return sol;
}

int main(void) {
	int T, k, n;

	cin >> T;

	while (T > 0) {
		cin >> k;
		cin >> n;

		int ret = solution(k, n);
		cout << ret << endl;

		T--;
	}

	return 0;
}