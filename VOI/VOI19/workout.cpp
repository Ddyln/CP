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
const int INF = 1e17;
const int N = 2e5 + 5;

int n, m, k, d[4][N], f[2][N], st[2], fn[2], easy[2], dp[N];
bool vis[N];
vector <ii> a[N];
vector <iii> dag[2][N];
vector <iiii> E;
priority_queue <ii, vector <ii>, greater <ii>> pq;

void dijkstra(int u, int id) {
	for (int i = 1; i <= n; i++)
		d[id][i] = INF;
	d[id][u] = 0;
	pq.push({0, u});
	while (pq.size()) {
		u = pq.top().se;
		int du = pq.top().fi;
		pq.pop();
		if (du != d[id][u])
			continue;
		for (ii &e : a[u]) {
			int v = e.se, w = e.fi;
			if (d[id][v] > d[id][u] + w) {
				d[id][v] = d[id][u] + w;
				pq.push({d[id][v], v});
			}	
		}
	}
}

void prepare(int u, int s) {
	vis[u] = 1;
	for (iii e : dag[1][u]) {
		int v = e.se.se, w = e.se.fi, id = e.fi;
		f[1][id] = s;
		if (!vis[v]) 
			prepare(v, s + w);
	}
}

void cal(int u, int s) {
	vis[u] = 1;
	for (iii e : dag[0][u]) {
		int v = e.se.se, w = e.se.fi, id = e.fi;
		f[0][id] = s;
		if (!vis[v])
			cal(v, s + w);
		if (f[1][id] != INF) {
			if (easy[2] || f[0][id] == f[1][id]) 
				dp[u] = max(dp[u], dp[v] + w);
		}
	}
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
		cin >> n >> m >> k;
		if (k != 2)
			return 0;
		for (int i = 1; i <= m; i++) {
			int u, v, w; cin >> u >> v >> w;
			a[u].push_back({w, v});
			a[v].push_back({w, u});
			E.push_back({{w, i}, {u, v}});
		}	
		cin >> st[1] >> fn[1];
		for (int i = 2; i <= k; i++) 
			cin >> easy[i] >> st[i] >> fn[i];
		dijkstra(st[1], 0);
		dijkstra(fn[1], 1);
		dijkstra(st[2], 2);
		dijkstra(fn[2], 3);
		for (iiii &e : E) {
			int u = e.se.fi, v = e.se.se, w = e.fi.fi, id = e.fi.se;
			if (d[0][u] + w + d[1][v] == d[0][fn[1]])
				dag[0][u].push_back({id, {w, v}});
			if (d[0][v] + w + d[1][u] == d[0][fn[1]])
				dag[0][v].push_back({id + m, {w, u}});
			if (d[2][u] + w + d[3][v] == d[2][fn[2]])
				dag[1][u].push_back({id, {w, v}});
			if (d[2][v] + w + d[3][u] == d[2][fn[2]])
				dag[1][v].push_back({id + m, {w, u}});
		}
		for (int i = 1; i <= 2 * m; i++)
			f[0][i] = f[1][i] = INF;
		prepare(st[2], 0);
		for (int i = 1; i <= n; i++)
			vis[i] = 0;
		cal(st[1], 0);
		int res = 0;
		for (int i = 1; i <= n; i++)
			res = max(res, dp[i]);
		cout << res;
	}

	return 0;
}