#include<iostream>
#include<queue>
#include<algorithm>
#include<cstdlib>
#include<vector>
#include<stack>
#include<cstring>

using namespace std;

char alpha[21][21];
int r, c;
int maxnum = 0;

int dx[4] = { 1, 0, 0, -1 };
int dy[4] = { 0, 1, -1, 0 };

typedef pair<int, int> pp;

typedef struct node {
	int x, y;
	int parent_num;
	int alpha_visit[26] = { 0, };
}node;

void dfs() {

	int flag;
	int tx, ty;
	stack<node> s;
	node temp;
	temp.x = temp.y = temp.parent_num = 0;
	temp.alpha_visit[alpha[0][0] - 65] = 1;

	s.push(temp);

	while (!s.empty()) {
		temp = s.top();
		s.pop();
		flag = 0;

		for (int i = 0; i < 4; i++) {

			tx = temp.x + dx[i];
			ty = temp.y + dy[i];

			if (tx < 0 || tx >= c || ty < 0 || ty >= r)
				continue;

			int tmp = alpha[ty][tx] - 65;

			if (temp.alpha_visit[tmp] == 1)
				continue;

			node child;
			child.x = tx;
			child.y = ty;
			child.parent_num = temp.parent_num + 1;

			memcpy(child.alpha_visit, temp.alpha_visit, sizeof(temp.alpha_visit));
			child.alpha_visit[tmp] = 1;

			if (flag == 0) {
				flag = 1;
			}
			s.push(child);
		}

		if (flag == 0) {
			if (maxnum < temp.parent_num + 1) {
				maxnum = temp.parent_num + 1;
			}
		}

	}

}

int main(void) {

	cin >> r >> c;

	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++)
			cin >> alpha[i][j];
	}

	dfs();

	cout << maxnum;

	return 0;
}