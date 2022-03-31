#include<iostream>
#include<algorithm>
#include<array>
#include<vector>

using namespace std;

int main(void) {

	vector<int> arr;
	int N;

	cin >> N;

	for (int i = 0; i < N; i++) {
		int x;
		cin >> x;
		arr.push_back(x);
	}

	if (prev_permutation(arr.begin(), arr.end())) {
		for (auto element : arr)
			cout << element << " ";
		cout << endl;
	}
	else {
		cout << -1;
	}

	return 0;
}