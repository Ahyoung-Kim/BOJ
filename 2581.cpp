#include<iostream>
#include<cstdlib>
#include<cstring>
#include<string>
#include<cmath>

using namespace std;

int solution(int n) {
	if (n == 1)
		return 0;
	if (n == 2)
		return n;

	for (int i = 2; i <= sqrt(n); i++) {
		if (n % i == 0)
			return 0;
	}
	return n;
}

int main(void) {
	int M, N;
	int ans = 0, min = 0;
	int flag = 0;

	cin >> M >> N;

	for (int i = M; i <= N; i++) {
		int ret = solution(i);
		if (ret == 0)
			continue;

		if (flag == 0) {
			min = ret;
			flag = 1;
		}

		ans += ret;
	}

	if (flag == 0) {
		cout << -1 << endl;
	}
	else {
		cout << ans << endl;
		cout << min << endl;
	}

	return 0;
}