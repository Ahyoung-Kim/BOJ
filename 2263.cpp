#include<iostream>
#include<vector>

using namespace std;

int n;
int root;
vector<int> in;
vector<int> post;
int ans[100001] = { 0, };
int idx = 0;

void solution(int pIdx, int s, int e) {
	int left, right;
	int i;
	ans[idx++] = post[pIdx];

	if (s >= e)
		return;

	for (i = s; i <= e; i++) {
		if (in[i] == post[pIdx]) {
			left = i - s;
			right = e - i;
			break;
		}
	}

	if (left > 0) {
		solution(pIdx - right - 1, s, i - 1);
	}
	if (right > 0) {
		solution(pIdx - 1, i + 1, e);
	}
	  
}

int main(void) {

	cin >> n;

	for (int i = 1; i <= n; i++) {
		int x;
		cin >> x;
		in.push_back(x);
	}
	for (int i = 1; i <= n; i++) {
		int x;
		cin >> x;
		post.push_back(x);

		if (i == n) {
			root = x;
		}
	}

	solution(n - 1, 0, n - 1);

	for (int i = 0; i < n; i++) {
		cout << ans[i] << " ";
	}

	return 0;
}