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

#define MAX 1001

int s;
bool visit[MAX][MAX] = { false, };

typedef struct node {
	int w;
	int c;
	int depth;
};

int bfs() {
	queue<node> q;

	visit[1][0] = true;
	q.push({ 1, 0, 0 });

	while (!q.empty()) {
		node curr = q.front();
		q.pop();

		if (curr.w == s) {
			return curr.depth;
		}

		for (int i = 0; i < 3; i++) {
			int tc = curr.c;
			int tw = curr.w;

			if (i == 0) { //Ŭ�����忡 ����
				tc = curr.w;
			}
			else if (i == 1) { //ȭ�鿡 �ٿ��ֱ�
				tw = curr.w + curr.c;
			}
			else { //�ϳ� ����
				tw = curr.w - 1;
			}

			if (tc <= 0 || tc > s || tw<0 || tw>s)
				continue;
			if (visit[tw][tc])
				continue;

			visit[tw][tc] = true;
			q.push({ tw, tc, curr.depth + 1 });
		}
	}
}

int main(void) {

	cin >> s;

	int ret = bfs();

	cout << ret;

	return 0;
}