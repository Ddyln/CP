#include <bits/stdc++.h>
using namespace std;

#define Fname ((string) "sc2")
#define int long long
#define ii pair <int, int>
#define iii pair <int, ii>
#define fi first
#define se second
#define endl '\n'

int k, a[3];

bool check(int x) {
	int all = 0;
	for (int mask = 1; mask < 8; mask++) {
		int cnt = 0, s = 1;
		for (int i = 0; i < 3; i++)
			if (mask & (1 << i)) {
				cnt++;
				s *= a[i];
			}
		if (cnt % 2 == 1)
			all += x / s;
		else
			all -= x / s;
	}
	return (all >= k);
}

int cnp(int l, int r) {
	if (l == r)
		return l;
	int m = (l + r) / 2;
	if (check(m))
		return cnp(l, m);
	return cnp(m + 1, r);
}

signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	freopen((Fname + ".inp").c_str(), "r", stdin);
	freopen((Fname + ".out").c_str(), "w", stdout);

	a[0] = 3;
	a[1] = 5;
	a[2] = 7;
	int _nt; cin >> _nt;
	// int _nt = 1;
	while (_nt--) {
		cin >> k;
		cout << cnp(1, 1842105263157894738) << endl;
	}

	return 0;
}