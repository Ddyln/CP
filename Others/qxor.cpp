#include <bits/stdc++.h>
using namespace std;

#define Fname ((string) "test")
#define int long long
#define ii pair <int, int>
#define iii pair <int, ii>
#define fi first
#define se second
#define endl '\n'

const int N = 1e5 + 5;

int n, q, a[N], st[4 * N];

void Build(int id, int l, int r) {
	if (l == r)
		return void(st[id] = a[l]);
	int m = (l + r) / 2;
	Build(id * 2, l, m);
	Build(id *2 + 1, m + 1, r);
	st[id] = st[id * 2] ^ st[id * 2 + 1];
}

void Update(int id, int l, int r, int p, int val) {
	if (r < p || l > p)
		return;
	if (l == r)
		return void(st[id] ^= val);
	int m = (l + r) / 2;
	Update(id * 2, l, m, p, val);
	Update(id * 2 + 1, m + 1, r, p, val);
	st[id] = st[id *2] ^ st[id * 2 + 1];
}

int Get(int id, int l, int r, int u, int v) {
	if (r < u || l > v)
		return 0;
	if (l >= u && r <= v)
		return st[id];
	int m = (l + r) / 2;
	return Get(id * 2, l, m, u, v) ^ Get(id * 2 + 1, m + 1, r, u, v);
}

signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	#ifdef lan_ngu
		freopen((Fname + ".inp").c_str(), "r", stdin);
		freopen((Fname + ".out").c_str(), "w", stdout);
	#endif

	// int _nt; cin >> _nt;
	int _nt = 1;
	while (_nt--) {
		cin >> n >> q;
		for (int i = 1; i <= n; i++)	
			cin >> a[i];
		Build(1, 1, n);
		while (q--) {
			int t, l, r;
			cin >> t >> l >> r;
			if (t == 1)
				Update(1, 1, n, l, r);
			else
				cout << Get(1, 1, n, l, r) << endl;
		}
	}
	
	return 0;
}