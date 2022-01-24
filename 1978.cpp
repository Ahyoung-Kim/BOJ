#include<iostream>
#include<cstdlib>
#include<cstring>
#include<string>
#include<cmath>

using namespace std;

int num[1001];

int solution(int n) {
	if (n == 1)
		return 0;
	if (n == 2)
		return 1;

	for (int i = 2; i <= sqrt(n); i++) {
		if (n % i == 0)
			return 0;
	}
	return 1;
}

int main(void) {
	int N;
	int ans = 0;

	cin >> N;

	for (int i = 0; i < N; i++)
		cin >> num[i];

	for (int i = 0; i < N; i++) {
		int ret = solution(num[i]);
		if (ret == 1)
			ans++;
	}

	cout << ans << endl;

	return 0;
}