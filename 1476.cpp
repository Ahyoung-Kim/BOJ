#include<iostream>
#include<vector>
#include<queue>
#include<cmath>
#include<cstdlib>
#include<algorithm>

using namespace std;

int main(void) {
	int E, S, M;
	int ans = 1;

	cin >> E >> S >> M;

	while (true) {
		if ((ans - E) % 15 == 0 && (ans - S) % 28 == 0 && (ans - M) % 19 == 0) {
			cout << ans;
			return 0;
		}
		ans++;
	}

	return 0;
}