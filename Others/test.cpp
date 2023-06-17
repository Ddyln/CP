#include <bits/stdc++.h>
using namespace std;

int cnp(int l, int r, int password, int k) {
	if (l >= r)
		return 0;
	if (k == 1)
		return (password - l + 1) * (password + l) / 2;
	int m = (l + r) / 2;
	if (m == password)
		return m;
	if (m < password)
		return m + cnp(m + 1, r, password, k);
	return m + cnp(l, m - 1, password, k - 1);
}

signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	freopen("test.inp", "r", stdin);
	freopen("test.out", "w", stdout);
	int _t, k, m, tmp;
	cin >> _t;
	while (_t--) {
		int res = 0;
		cin >> k >> m;
		for (int i = 1; i <= m; i++) {
			res = max(res, tmp = cnp(1, m, i, k));
		}
		cout << res << endl;
	}
}