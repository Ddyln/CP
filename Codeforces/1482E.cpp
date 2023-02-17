#include <bits/stdc++.h>
using namespace std;

#define Fname ((string) "test")
#define int long long
#define ii pair <int, int>
#define iii pair <int, ii>
#define fi first
#define se second
#define endl '\n'
const int N = 3e5 + 5;
const int INF = 1e16;

int n, h[N], b[N], f[N], lmin[N], st[4 * N];
deque <int> dq;

void update(int id, int l, int r, int p, int v) {
	if (r < p || l > p)
		return;
	if (l == r)
		return void(st[id] = v);
	int m = (l + r) / 2;
	update(id * 2, l, m, p, v);
	update(id * 2  + 1, m + 1, r, p, v);
	st[id] = max(st[id * 2], st[id * 2 + 1]);
}

int get(int id, int l, int r, int u, int v) {
	if (r < u || l > v || u > v)
		return -INF;
	if (l >= u && r <= v)
		return st[id];
	int m = (l + r) / 2;
	return max(get(id * 2, l, m, u, v), get(id * 2 + 1, m + 1, r, u, v));
}

signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	#ifdef lan_ngu
		freopen((Fname + ".inp").c_str(), "r", stdin);
		freopen((Fname + ".ans").c_str(), "w", stdout);
	#endif

	// int _nt; cin >> _nt;
	int _nt = 1;
	while (_nt--) {
		cin >> n;
		for (int i = 1; i <= n; i++)
			cin >> h[i];
		for (int i = 1; i <= n; i++)
			cin >> b[i];
		dq.push_back(0);
		for (int i = 1; i <= n; i++) {
			while (dq.size() > 1 && h[dq.back()] > h[i])
				dq.pop_back();
			lmin[i] = dq.back() + 1;
			dq.push_back(i);
		}
		f[0] = -INF;
		for (int i = 1; i <= n; i++) {
			f[i] = max(get(1, 0, n, lmin[i] - 1, i - 1) + b[i], f[lmin[i] - 1]);
			update(1, 0, n, i, f[i]);
			cout << f[i] << ' ';
		}
		cout << f[n];
	}

	return 0;
}