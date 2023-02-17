#include <bits/stdc++.h>
using namespace std;

int main() {
	freopen("vitrile.inp", "r", stdin);
	freopen("vitrile.out", "w", stdout);
	string s;
	getline(cin, s);
	for (int i = 1; i < s.size(); i += 2)
		cout << s[i];
	return 0;
}