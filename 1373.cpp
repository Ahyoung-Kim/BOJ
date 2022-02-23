#include<iostream>
#include<stack>
#include<vector>
#include<cstring>
#include<string>
#include<cstdlib>
#include<queue>

using namespace std;

int main(void) {

	char bin[1000001];
	int len;
	vector<int> ans;

	cin >> bin;

	len = strlen(bin);

	for (int i = len - 1; i >= 0; i -= 3) {
		int k = 1;
		int temp = 0;
		for (int j = i; k <= 4; j--) {
			if (bin[j] == '1') {
				temp += k;
			}
			k *= 2;
		}
		ans.push_back(temp);
	}

	while (!ans.empty()) {
		cout << ans.back();
		ans.pop_back();
	}

	return 0;
}