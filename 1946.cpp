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

typedef pair<int, int> p;

int main(void) {

	int t;
	int n;

	cin >> t;

	while (t > 0) {

		int cnt = 1;
		cin >> n;
		vector<p> person;
		for (int i = 0; i < n; i++) {
			int a, b;
			cin >> a >> b;
			person.push_back({ a, b });
		}
		sort(person.begin(), person.end(),
			[](p a, p b) { return a.first < b.first; });

		int prev = person[0].second;

		for (int i = 1; i < n; i++) {
			if (person[i].second < prev) {
				cnt++;
				prev = person[i].second;
			}
		}
		cout << cnt << endl;

		t--;
	}

	return 0;
}