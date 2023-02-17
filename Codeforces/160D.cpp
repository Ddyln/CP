#include <bits/stdc++.h>
using namespace std;

#define Fname ((string) "test")
#define int long long
#define ii pair <int, int>
#define iii pair <int, ii>
#define iiii pair <ii, ii>
#define fi first
#define se second
#define endl '\n'
const int N = 1e5 + 5;

int n, m, Rank[N], par[N], ans[N];	
bool check[N * 10];
vector <iiii> E;

int find(int u) {
	return (par[u] == u ? u : par[u] = find(par[u]));
}

void merge(int u, int v) {
	if (Rank[u] < Rank[v])
		swap(u, v);
	Rank[u] += Rank[v];
	par[v] = u;
}

void kruskal() {
	sort(E.begin(), E.end());
	for (int i = 1; i <= n; i++)
		par[i] = i, Rank[i] = 1;
	for (iiii &e : E) {
		int u = e.se.fi, v = e.se.se, w = e.fi.fi;
		u = find(u);
		v = find(v);
		if (u == v) {
			if (ans[w] != 0)
				ans[w] = 1;
			continue;
		}
		ans[id] = 2;
		merge(u, v);
	}
}

string _(int n) {
	if (n == 0)
		return "none";
	if (n == 1)
		return "at least one";
	return "any";
}

bool cmp(const iiii &a, const iiii &b) {
	return a.fi.se < b.fi.se;
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
		for (int i = 1; i <= m; i++) {
			int u, v, w; cin >> u >> v >> w;
			E.push_back({{w, i}, {u, v}});
		}	
		kruskal();
		sort(E.begin(), E.end(), cmp);
		for (int i = 0; i < m; i++)
			cout << _(ans[E[i].fi.se]) << endl;
	}

	return 0;
}