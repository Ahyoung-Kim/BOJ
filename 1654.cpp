#include<iostream>
#include<vector>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<string>
#include<algorithm>
#include<queue>
#include<stack>

using namespace std;

int k, n;
long long ans;
vector<long long> line;

int main(void) {

	cin >> k >> n;

	for (int i = 0; i < k; i++) {
		int x;
		cin >> x;
		line.push_back(x);
	}
	sort(line.begin(), line.end());

	long long s = 1;
	long long e = line.back() + 1;

	while (s <= e) {
		long long mid = (s + e) / 2;
		long long sum = 0;

		for (int i = 0; i < k; i++) {
			if (line[i] >= mid) {
				sum += (line[i] / mid);
			}
		}

		if (sum >= n) {
			ans = max(ans, mid);
			s = mid + 1;
		}
		else {
			e = mid - 1;
		}
	}

	cout << ans;

	return 0;
}