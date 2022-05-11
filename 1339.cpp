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

int n;
int num[27] = { 0, };
vector<string> words;
priority_queue<int, vector<int>, less<int>> pq;

void set_num() {

	for (int i = 0; i < n; i++) {
		int pow = 1;
		for (int j = words[i].size() - 1; j >= 0; j--) {
			int alpha = words[i][j] - 65;
			num[alpha] += pow;
			pow *= 10;
		}
	}

	for (int i = 0; i < 27; i++) {
		if (num[i] != 0)
			pq.push(num[i]);
	}
}

int solution() {

	int sum = 0;
	int cnt = 9;

	while (!pq.empty()) {
		sum += (pq.top() * cnt);
		pq.pop();
		cnt--;
	}

	return sum;
}

int main(void) {

	cin >> n;

	for (int i = 0; i < n; i++) {
		string temp;
		cin >> temp;
		words.push_back(temp);
	}
	sort(words.begin(), words.end(),
		[](string a, string b) { return a.size() > b.size(); });

	set_num();
	cout << solution() << endl;


	return 0;
}