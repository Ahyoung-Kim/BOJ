#include<iostream>
#include<stack>
#include<vector>

using namespace std;

typedef struct info {
	int a;
	int f;
}info;

info arr[1000001];
stack<info> s;
int N;
int ans[1000001];
int F[1000001];

int main(void) {

	cin >> N;
	int temp;
	info tinfo;

	for (int i = 0; i < N; i++) {
		cin >> temp;
		arr[i].a = temp;
		F[temp]++;
	}

	for (int i = 0; i < N; i++) {
		temp = arr[i].a;
		arr[i].f = F[temp];
	}

	for (int i = N - 1; i >= 0; i--) {
		while (!s.empty() && s.top().f <= arr[i].f)
			s.pop();

		if (s.empty())
			ans[i] = -1;
		else {
			ans[i] = s.top().a;
		}

		s.push(arr[i]);
	}

	for (int i = 0; i < N; i++)
		cout << ans[i] << " ";

	return 0;
}