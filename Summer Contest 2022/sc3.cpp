#include <bits/stdc++.h>
using namespace std;

#define Fname ((string) "sc3")
#define int long long
#define ii pair <int, int>
#define iii pair <int, ii>
#define fi first
#define se second
#define endl '\n'
const int N = 1e5 + 5;

int n, q, par[N][20], sum[N][20], tIn[N], tOut[N], Time, pre[N], Rank[N];
bool vis[N];
vector <ii> a[N];
vector <iii> query;

void dfs(int u) {
	vis[u] = 1;
	tIn[u] = ++Time;
	for (int i = 1; i <= 16; i++) {
		par[u][i] = par[par[u][i - 1]][i - 1];
		sum[u][i] = sum[u][i - 1] + sum[par[u][i - 1]][i - 1];
	}
	for (ii tmp : a[u]) {
		int  v = tmp.se, w = tmp.fi;
		if (!vis[v]) {
			par[v][0] = u;
			sum[v][0] = w;
			dfs(v);
		}
	}
	tOut[u] = ++Time;
}

bool isAncestor(int u, int v) {
	return (tIn[u] <= tIn[v] && tOut[u] >= tOut[v]);
}

int lca(int u, int v) {
	if (isAncestor(u, v))
		return u;
	if (isAncestor(v, u))
		return v;
	for (int i = 16; i >= 0; i--)
		if (par[u][i] != 0 && !isAncestor(par[u][i], v))
			u = par[u][i];
	return par[u][0];
}

int find(int u) {
	return (pre[u] == u ? u : pre[u] = find(pre[u]));
}

void merge(int u, int v) {
	if (Rank[u] < Rank[v])
		swap(u, v);
	Rank[u] += Rank[v];
	pre[v] = u;
}

int get(int u, int v) {
	if (u == v)
		return 0;
	int res = 0;
	for (int i = 16; i >= 0; i--)
		if (par[u][i] != 0 && par[u][i] != v && isAncestor(v, par[u][i]))
			res += sum[u][i], u = par[u][i];
	return res + sum[u][0];
}

signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	freopen((Fname + ".inp").c_str(), "r", stdin);
	freopen((Fname + ".out").c_str(), "w", stdout);

	int _nt; cin >> _nt;
	// int _nt = 1;
	while (_nt--) {
		cin >> n >> q;
		Time = 0;
		for (int i = 1; i <= n; i++) {
			vis[i] = 0;
			Rank[i] = 1;
			pre[i] = i;
			a[i].clear();
			for (int j = 0; j <= 16; j++)
				par[i][j] = sum[i][j] = 0;
		}
		query.clear();
		for (int i = 1; i <= q; i++) {
			char t; cin >> t;
			if (t == '!') {
				int u, v, w; cin >> u >> v >> w;
				a[u].push_back({w, v});
				a[v].push_back({-w, u});
				query.push_back({0, {u, v}});
			} else {
				int u, v; cin >> u >> v;
				query.push_back({1, {u, v}});
			}
		}
		for (int i = 1; i <= n; i++)
			if (!vis[i])
				dfs(i);
		for (int i = 0; i < q; i++) {
			int t = query[i].fi, u = query[i].se.fi, v = query[i].se.se;
			if (t == 0) {
				u = find(u);
				v = find(v);
				if (u == v)
					continue;
				merge(u, v);
			} else {
				u = find(u);
				v = find(v);
				if (u != v) {
					cout << "UNKNOWN\n";
					continue;
				}
				u = query[i].se.fi;
				v = query[i].se.se;
				int k = lca(u, v);
				cout << get(v, k) - get(u, k) << endl;
			}
		}
	}

	return 0;
}