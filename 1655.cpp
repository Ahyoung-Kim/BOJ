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
priority_queue<int> maxHeap;
priority_queue<int, vector<int>, greater<int>> minHeap;

void insert(int x) {
	if (maxHeap.size() == 0) {
		maxHeap.push(x);
		return;
	}

	if (maxHeap.size() == minHeap.size()) {
		maxHeap.push(x);
	}
	else {
		minHeap.push(x);
	}

	if (maxHeap.top() > minHeap.top()) {
		maxHeap.push(minHeap.top());
		minHeap.pop();
		minHeap.push(maxHeap.top());
		maxHeap.pop();
	}
}

int main(void) {

	scanf("%d", &N);

	for (int i = 0; i < N; i++) {
		int x;
		scanf("%d", &x);

		insert(x);

		printf("%d\n", maxHeap.top());
	}

	return 0;
}