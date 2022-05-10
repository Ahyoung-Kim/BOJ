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

	int n;
	vector<p> meeting;  //first: 시작 시간, second: 종료 시간

	cin >> n;
	for (int i = 0; i < n; i++) {
		int start, end;
		cin >> start >> end;
		meeting.push_back({ start, end });
	}
	sort(meeting.begin(), meeting.end(),
		[](p a, p b)
		{
			if (a.second == b.second)
				return a.first < b.first;
			return a.second < b.second;
		});

	int time = meeting[0].second;
	int ans = 1;
	for (int i = 1; i < n; i++) {
		if (time <= meeting[i].first) {
			ans++;
			time = meeting[i].second;
		}
	}

	cout << ans;

	return 0;
}