#include <bits/stdc++.h>
using namespace std;

#define Fname ((string) "test")
#define int long long
#define ii pair <int, int>
#define iii pair <int, ii>
#define fi first
#define se second
#define endl '\n'
const int N = 1005;
const int INF = 1e16;

int n, m, k, d[N][N], res;
vector <ii> a[N], E, q;
priority_queue <ii, vector <ii>, greater <ii>> pq;

void dijkstra(int src) {
	for (int i = 1; i <= n; i++)
		d[src][i] = INF;
	d[src][src] = 0;
	pq.push({0, src});
	while (pq.size()) {
		int u = pq.top().se, du = pq.top().fi;
		pq.pop();
		if (du != d[src][u])
			continue;
		for (ii &e : a[u]) {
			int v = e.se, w = e.fi;
			if (d[src][v] > du + w) {
				d[src][v] = du + w;
				pq.push({du + w, v});
			}
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
		for (int i = 1; i <= m; i++) {
			int u, v, w; cin >> u >> v >> w;
			a[u].push_back({w, v});
			a[v].push_back({w, u});
			E.push_back({u, v});
		}	
		for (int i = 1; i <= k; i++) {
			int u, v; cin >> u >> v;
			q.push_back({u, v});
		}
		for (int i = 1; i <= n; i++)
			dijkstra(i);
		res = INF;
		for (ii &e : E) {
			int u = e.fi, v = e.se, cur = 0;
			for (ii &tmp : q) {
				int x = tmp.fi, y = tmp.se;
				cur += min({d[x][u] + d[y][v], d[x][v] + d[y][u], d[x][y]});
			}
			res = min(res, cur);
		}
		cout << res;
	}

	return 0;
}