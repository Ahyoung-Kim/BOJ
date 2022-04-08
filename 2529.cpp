#include<iostream>
#include<vector>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<string>
#include<algorithm>

using namespace std;

typedef pair<int, int> tp;

int k;
char comp[10];
bool visit[10] = { false, };
bool max_flag = false;
bool min_flag = false;
string max_str;
string min_str;

void max_dfs(int num, string str, int depth) {

	if (max_flag)
		return;

	if (depth == k) {
		max_flag = true;
		max_str = str;
		return;
	}

	char c = comp[depth];

	if (c == '<') {
		for (int i = 9; i >= 0; i--) {
			if (max_flag)
				break;
			if (num < i && !visit[i]) {
				visit[i] = true;
				max_dfs(i, str + to_string(i), depth + 1);
				visit[i] = false;
			}
		}
	}
	else if (c == '>') {
		for (int i = 9; i >= 0; i--) {
			if (max_flag)
				break;
			if (num > i && !visit[i]) {
				visit[i] = true;
				max_dfs(i, str + to_string(i), depth + 1);
				visit[i] = false;
			}
		}
	}
}

void min_dfs(int num, string str, int depth) {

	if (min_flag)
		return;

	if (depth == k) {
		min_flag = true;
		min_str = str;
		return;
	}

	char c = comp[depth];

	if (c == '<') {
		for (int i = 0; i <= 9; i++) {
			if (min_flag)
				break;
			if (num < i && !visit[i]) {
				visit[i] = true;
				min_dfs(i, str + to_string(i), depth + 1);
				visit[i] = false;
			}
		}
	}
	else if (c == '>') {
		for (int i = 0; i <= 9; i++) {
			if (min_flag)
				break;
			if (num > i && !visit[i]) {
				visit[i] = true;
				min_dfs(i, str + to_string(i), depth + 1);
				visit[i] = false;
			}
		}
	}
}

int main(void) {

	cin >> k;

	for (int i = 0; i < k; i++)
		cin >> comp[i];

	for (int i = 9; i >= 0; i--) {
		visit[i] = true;
		max_dfs(i, to_string(i), 0);
		visit[i] = false;
	}

	memset(visit, false, sizeof(visit));

	for (int i = 0; i <= 9; i++) {
		visit[i] = true;
		min_dfs(i, to_string(i), 0);
		visit[i] = false;
	}


	cout << max_str << endl;
	cout << min_str << endl;

	return 0;
}