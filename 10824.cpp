#include<iostream>
#include<stack>
#include<vector>
#include<cstring>
#include<string>
#include<cstdlib>

using namespace std;

int main(void) {

	int A, B, C, D;

	cin >> A >> B >> C >> D;

	string str1 = to_string(A) + to_string(B);
	string str2 = to_string(C) + to_string(D);
	long long ans = stoll(str1) + stoll(str2);

	cout << ans << endl;

	return 0;
}