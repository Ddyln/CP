#include <bits/stdc++.h>
using namespace std;

#define Fname ((string) "test")
#define int long long
#define ii pair <int, int>
#define iii pair <int, ii>
#define fi first
#define se second
#define endl '\n'

bool kt(int mask, int i) {
	return !(mask & (1 << i));
}

void print(int n, int step = 0) {
	if (n == 0)
		return;
	print(n / 2, step + 1);
	cout << n % 2;
	if (!step)
		cout << endl;
}

void sol() {
	int cnt = 0, n = 0;
	cin >> n;
	for (int i = 0; i < (1 << n); i++) {
		bool ok = __builtin_popcount(i) % 2;
		cnt += ok;
	}
	cout << cnt;
}

signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	#ifdef lan_ngu
		// freopen((Fname + ".inp").c_str(), "r", stdin);
		// freopen((Fname + ".out").c_str(), "w", stdout);
	#endif

	// int _nt; cin >> _nt;
	int _nt = 1;
	while (_nt--) {
		// sol();
		map <int, int> mp;
		mp.insert({1, 2});
		for (auto x : mp)
			cout << x.fi << ' ';
	}
	
	return 0;
}