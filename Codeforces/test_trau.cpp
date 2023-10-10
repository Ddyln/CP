#include <bits/stdc++.h>
using namespace std;

int main() {
	freopen("test.inp", "r", stdin);
	freopen("test.ans", "w", stdout);
	int n = 0;
	cin >> n;
	vector <int> a(n);
	for (int i = 0; i < n; i++)
		cin >> a[i];
	sort(a.begin(), a.end());
	for (int i = 0; i < n; i++)
		cout << a[i] << ' ';
	return 0;
}