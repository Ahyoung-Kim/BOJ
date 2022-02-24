#include<iostream>
#include<stack>
#include<vector>
#include<cstring>
#include<string>
#include<cstdlib>
#include<queue>
#include<algorithm>

using namespace std;

int main(void) {

	int n;
	priority_queue<int, vector<int>, greater<int>> p;

	cin >> n;

	for (int i = 0; i < n; i++) {
		int temp;
		cin >> temp;
		p.push(temp);
	}

	int prev;
	int result;

	prev = result = p.top();
	p.pop();

	while (!p.empty()) {
		prev = prev + p.top();
		result += prev;
		p.pop();
	}

	cout << result;

	return 0;
}