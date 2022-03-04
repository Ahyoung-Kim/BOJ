#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
#include<cstdlib>
#include<cstring>
#include<array>

using namespace std;

int main(void) {

	int N, B;
	vector<char> ans;

	cin >> N >> B;

	while (N > 0) {
		int temp = N % B;
		char c;

		if (temp >= 10 && temp <= 35) {
			c = temp + 55;
		}
		else {
			c = temp + 48;
		}

		ans.push_back(c);

		N /= B;
	}

	while (!ans.empty()) {
		cout << ans.back();
		ans.pop_back();
	}

	return 0;
}