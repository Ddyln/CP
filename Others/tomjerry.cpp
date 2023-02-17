#include <bits/stdc++.h>
using namespace std;

int main() {
	freopen("tomjerry.inp", "r", stdin);
	freopen("tomjerry.out", "w", stdout);
	string s;
	int tom = 0, jerry = 0, n;
	cin >> n >> s;
	for (int i = 0; i < n; i++)
		if (s[i] == 'T')
			tom += 3;
		else if (s[i] == 'J')
			jerry += 3;
	cout << tom << endl << jerry;
	return 0;
}