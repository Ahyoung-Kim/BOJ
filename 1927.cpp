#include<iostream>
#include<vector>
#include<queue>
#include<cmath>
#include<cstdlib>
#include<algorithm>
#include<string>
#include<cstring>
#include<cstdio>

using namespace std;

int N;
priority_queue<int, vector<int>, greater<int>> minHeap;

void remove() {
	if (minHeap.size() == 0) {
		printf("%d\n", 0);
		return;
	}
	printf("%d\n", minHeap.top());
	minHeap.pop();
}

int main(void) {

	scanf("%d", &N);

	for (int i = 0; i < N; i++) {
		int x;
		scanf("%d", &x);

		if (x == 0)
			remove();
		else
			minHeap.push(x);
	}

	return 0;
}