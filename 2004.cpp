#include<iostream>
#include<stack>
#include<vector>
#include<cstring>
#include<string>

using namespace std;

long long funct(int n, int k) {
	long long ans = 0;

	for (long long i = k; i <= n; i *= k) {
		ans += n / i;
	}

	return ans;
}

int main(void) {

	cin.tie(NULL);
	cout.tie(NULL);

	ios_base::sync_with_stdio(false);

	int n, m;
	long long num2, num5;
	long long ans;

	cin >> n >> m;

	num2 = funct(n, 2) - (funct(m, 2) + funct(n - m, 2));
	num5 = funct(n, 5) - (funct(m, 5) + funct(n - m, 5));

	if (num2 < num5)
		ans = num2;
	else
		ans = num5;

	cout << ans;

	return 0;
}