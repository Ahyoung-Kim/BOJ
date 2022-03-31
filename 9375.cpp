#include<iostream>
#include<algorithm>
#include<array>
#include<vector>
#include<cmath>
#include<cstdlib>
#include<string>

using namespace std;

class hash_map {
	vector<string> data[31];
	string hashing[31];
	int size;

public:
	hash_map() {
		size = 0;
	}

	int find_index(string category) {

		if (size == 0) {
			hashing[0] = category;
			size++;
			return 0;
		}

		for (int i = 0; i < size; i++) {
			if (hashing[i].compare(category) == 0) {
				return i;
			}
		}
		return -1;
	}

	void insert(string name, string category) {

		int idx = find_index(category);

		if (idx == -1) {
			hashing[size] = category;
			data[size].push_back(name);
			size++;
		}
		else {
			data[idx].push_back(name);
		}
	}

	void print() {
		for (int i = 0; i < size; i++) {
			cout << "category " << hashing[i] << ": ";
			for (int j = 0; j < data[i].size(); j++) {
				cout << data[i][j] << " ";
			}
			cout << endl;
		}
	}

	int solution() {
		int ans = 1;

		for (int i = 0; i < size; i++) {
			ans *= (data[i].size() + 1);
		}
		return ans - 1;
	}
};

int main(void) {

	int t, n;

	scanf("%d", &t);

	while (t > 0) {

		scanf("%d", &n);
		hash_map map;

		string s1, s2;

		for (int i = 0; i < n; i++) {
			cin >> s1 >> s2;
			map.insert(s1, s2);
		}

		map.print();

		cout << map.solution() << endl;

		t--;
	}

	return 0;
}