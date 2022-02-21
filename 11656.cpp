#include<iostream>
#include<stack>
#include<vector>
#include<cstring>
#include<string>
#include<cstdlib>
#include<array>

using namespace std;

int main(void) {

	string str;
	string seq[1001];
	string min;
	int min_idx;
	int flag = 0;

	cin >> str;

	for (int i = 0; i < str.size(); i++) {
		seq[i] = str.substr(i);
	}

	for (int i = 0; i < str.size() - 1; i++) {
		min = seq[i];
		min_idx = i;
		for (int j = i + 1; j < str.size(); j++) {
			if (min > seq[j]) {
				min = seq[j];
				min_idx = j;
				flag = 1;
			}
		}
		if (flag == 1) {
			swap(seq[i], seq[min_idx]);
			flag = 0;
		}
	}

	for (int i = 0; i < str.size(); i++)
		cout << seq[i] << endl;

	return 0;
}