#include <bits/stdc++.h>
using namespace std;

#define Fname ((string) "test")
#define int long long
#define ii pair <int, int>
#define iii pair <int, ii>
#define fi first
#define se second
#define endl '\n'
const int N = 2e5 + 5;

int n, m, ans[N], par[N], Rank[N];
vector <iii> E;

int find(int u) {
	return (par[u] == u ? u : par[u] = find(par[u]));
}

int C(int n) {
	return (n * (n - 1)) / 2;
}

void kruskal() {
	for (int i = 1; i <= n; i++)
		Rank[i] = 1, par[i] = i;
	sort(E.begin(), E.end());
	int cur = 0, j = 1;
	for (iii &e : E) {
		int w = e.fi, u = e.se.fi, v = e.se.se;
		while (j < w)
			ans[j++] = cur;
		u = find(u); v = find(v);
		if (u == v) continue;
		cur -= C(Rank[u]) + C(Rank[v]);
		if (Rank[u] < Rank[v])
			swap(u, v);
		par[v] = u;
		Rank[u] += Rank[v];
		cur += C(Rank[u]);
	}
	while (j < N)
		ans[j++] = cur;
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
		for (int i = 1; i < n; i++) {
			int u, v, w; cin >> u >> v >> w;
			E.push_back({w, {u, v}});
		}
		kruskal();
		while (m--) {
			int tmp; cin >> tmp;
			cout << ans[tmp] << ' ';
		}
	}

	return 0;
}