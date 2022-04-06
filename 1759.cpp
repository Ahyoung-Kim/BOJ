#include<iostream>
#include<vector>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<string>
#include<algorithm>

using namespace std;

int L, C;
char alphabet[16];
char arr[16];
bool visit[16] = { false, };

bool is_consonant(char c) {
	if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u')
		return false;
	return true;
}

void dfs(int idx, int c, int v, int depth) {

	if (depth == L && c > 1 && v > 0) {
		for (int i = 0; i < L; i++)
			cout << arr[i];
		cout << endl;
		return;
	}
	else if (depth == L && (c < 2 || v < 1))
		return;

	for (int i = idx + 1; i < C; i++) {
		if (!visit[i]) {
			visit[i] = true;
			char ch = alphabet[i];
			arr[depth] = ch;
			if (is_consonant(ch))
				dfs(i, c + 1, v, depth + 1);
			else
				dfs(i, c, v + 1, depth + 1);
			visit[i] = false;
		}
	}

}

int main(void) {

	cin >> L >> C;

	for (int i = 0; i < C; i++) {
		cin >> alphabet[i];
	}

	sort(alphabet, alphabet + C);

	for (int i = 0; i < C; i++) {
		memset(visit, false, sizeof(visit));
		arr[0] = alphabet[i];
		visit[i] = true;
		int c = 0;
		int v = 0;
		if (is_consonant(alphabet[i])) {
			c++;
		}
		else {
			v++;
		}
		dfs(i, c, v, 1);
	}

	return 0;
}