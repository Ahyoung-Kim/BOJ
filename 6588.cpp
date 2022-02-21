#include<iostream>
#include<stack>
#include<vector>
#include<cstring>
#include<string>
#include<cstdlib>
#include<array>
#include<cmath>

using namespace std;

int dp[1000001] = { 0, };

int main(void) {

	cin.tie(NULL);
	cout.tie(NULL);

	ios_base::sync_with_stdio(false);

	int n;
	bool flag = false;

	for (int i = 2; i * i <= 1000000; i++) {
		if (dp[i] == 0) {
			for (int j = i * i; j <= 1000000; j += i) {
				dp[j] = 1;
			}
		}
	}

	while (1) {
		cin >> n;

		if (n == 0)
			break;

		if (n % 2 == 1)
			continue;

		flag = false;

		for (int i = 3; i < n; i += 2) {

			if (dp[i] == 0 && dp[n - i] == 0) {
				cout << n << " = " << i << " + " << n - i << endl;
				flag = true;
				break;
			}
		}

		if (flag == false)
			cout << "Goldbach's conjecture is wrong." << endl;
	}

	return 0;
}