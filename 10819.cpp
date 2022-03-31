#include<iostream>
#include<algorithm>
#include<array>
#include<vector>
#include<cmath>
#include<cstdlib>

using namespace std;

int main(void) {

	vector<int> arr;
	int N;
	int ans = 0;

	scanf("%d", &N);

	for (int i = 0; i < N; i++) {
		int x;
		scanf("%d", &x);
		arr.push_back(x);
	}

	sort(arr.begin(), arr.end());

	do {
		int sum = 0;

		for (auto it = arr.begin(); it != arr.end() - 1; it++) {
			sum += abs(*(it)-*(it + 1));
		}

		ans = max(ans, sum);
	} while (next_permutation(arr.begin(), arr.end()));

	printf("%d", ans);

	return 0;
}