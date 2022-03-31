#include<iostream>
#include<algorithm>
#include<array>
#include<vector>

using namespace std;

int main(void) {

	vector<int> arr;
	int N;

	scanf("%d", &N);

	for (int i = 1; i <= N; i++) {
		arr.push_back(i);
	}

	do {
		for (auto element : arr)
			printf("%d ", element);
		printf("\n");
	} while (next_permutation(arr.begin(), arr.end()));

	return 0;
}