#include<iostream>
#include<queue>
#include<algorithm>
#include<cstdlib>

#define buf 1000000009

using namespace std;

typedef class info {
public:
	long long n;
	long long one, two, three;

	info() {
		n = one = two = three = 0;
	};

	info(int N) {
		n = 1;
		if (N == 1) {
			one = 1;
			two = 0;
			three = 0;
		}
		else if (N == 2) {
			one = 0;
			two = 1;
			three = 0;
		}
		else if (N == 3) {
			n += 2;
			one = 1;
			two = 1;
			three = 1;
		}
	};
}info;

info dp[100001];

int main(void) {

	int t, n;
	info temp;

	temp = info(1);
	dp[1] = temp;
	temp = info(2);
	dp[2] = temp;
	temp = info(3);
	dp[3] = temp;

	cin >> t;

	while (t > 0) {

		cin >> n;

		if (dp[n].n == 0) {
			for (int i = 4; i <= n; i++) {

				if (dp[i].n != 0)
					continue;

				dp[i].one = (dp[i - 1].two + dp[i - 1].three) % buf;
				dp[i].two = (dp[i - 2].one + dp[i - 2].three) % buf;
				dp[i].three = (dp[i - 3].two + dp[i - 3].one) % buf;
				dp[i].n = (dp[i].one + dp[i].two + dp[i].three) % buf;

			}
		}

		cout << dp[n].n << endl;

		t--;
	}

	return 0;
}