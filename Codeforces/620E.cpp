#include <bits/stdc++.h>
using namespace std;

#define Fname ((string) "test")
#define int long long
#define ii pair <int, int>
#define iii pair <int, ii>
#define fi first
#define se second
#define endl '\n'
const int N = 4e5 + 5;

int n, m, tIn[N], Time, c[N], st[4 * N], lastUpdate[4 * N], ocl[N], ocr[N];
vector <int> topo, a[N];

void dfs(int u, int par) {
	topo.push_back(u);
	ocr[u] = ocl[u] = ++Time;
	for (int v : a[u])
		if (v != par) {
			dfs(v, u);
			ocr[u] = max(ocr[u], ocr[v]);
		}
}

void build(int id, int l, int r) {
	if (l == r) 
		return void(st[id] = c[topo[l - 1]]);
	int m = (l + r) / 2;
	build(id * 2, l, m);
	build(id * 2 + 1, m + 1, r);
	st[id] = st[id * 2] | st[id * 2 + 1];
}

void down(int id) {
	if (lastUpdate[id * 2] < lastUpdate[id]) {
		st[id * 2] = st[id];
		lastUpdate[id * 2] = lastUpdate[id];
	}
	if (lastUpdate[id * 2 + 1] < lastUpdate[id]) {
		st[id * 2 + 1] = st[id];
		lastUpdate[id * 2 + 1] = lastUpdate[id];
	}
}

int get(int id, int l, int r, int u, int v) {
	if (r < u || l > v)
		return 0;
	if (l >= u && r <= v)
		return st[id];
	down(id);
	int m = (l + r) / 2;
	return get(id * 2, l, m, u, v) | get(id * 2 + 1, m + 1, r, u, v);
}

void update(int id, int l, int r, int u, int v, int color) {
	if (r < u || l > v)
		return;
	if (l >= u && r <= v) {
		st[id] = 1LL << color;
		lastUpdate[id] = Time;
		return;
	}
	down(id);
	int m = (l + r) / 2;
	update(id * 2, l, m, u, v, color);
	update(id * 2 + 1, m + 1, r, u, v, color);
	st[id] = st[id * 2] | st[id * 2 + 1];
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
		cin >> n >> m;
		for (int i = 1; i <= n; i++) {
			int tmp; cin >> tmp;
			c[i] = 1LL << tmp;
		}
		for (int i = 1; i < n; i++) {
			int u, v;
			cin >> u >> v;
			a[u].push_back(v);
			a[v].push_back(u);
		}
		dfs(1, 1);
		build(1, 1, n);
		while (m--) {
			int t, u; cin >> t >> u;
			if (t == 1) {
				cin >> t;
				Time++;
				update(1, 1, n, ocl[u], ocr[u], t);
			} else 
				cout << __builtin_popcountll(get(1, 1, n, ocl[u], ocr[u])) << endl;
		}
	}

	return 0;
}