#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
#include<cstdlib>
#include<cstring>
#include<array>
#include<cmath>

using namespace std;

int main(void) {

	string N;
	int B;
	int ans = 0;
	int len;
	double p;

	cin >> N >> B;

	len = N.size() - 1;

	for (int i = 0; i < N.size(); i++) {
		char c = N[i];
		int temp;
		p = pow(B, len);

		if (c >= 'A' && c <= 'Z') {
			temp = c - 65 + 10;
		}
		else {
			temp = c - 48;
		}

		ans += temp * p;
		len--;
	}

	cout << ans;

	return 0;
}