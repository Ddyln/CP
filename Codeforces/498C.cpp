#include <bits/stdc++.h>
using namespace std;

#define Fname ((string) "test")
#define int long long
#define ii pair <int, int>
#define iii pair <int, ii>
#define fi first
#define se second
#define endl '\n'

int bfs() {
	for (int i = 1; i <= n; i++) {
		par[i] = -1;
		b[i] = a[i];
	}
	par[0] = 0;
	q.push({0, 0});
	while (!q.empty()) {
		int u = q.front().se, du = q.front().fi;
		q.pop();
		for (int v : a[u])
			if (u == 0) {
				par[v] = u;
				q.push({du, v});
			} else if (v == n)
				return du;
			else {
				
			}

	}
}

int maxflow() {
	int flow = 0, cur;
	while (cur = bfs()) {

	}
	return flow;
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
			cin >> a[i];
			if (i % 2 == 1) {
				adj[0].push_back(i);
				adj[i].push_back(0);
			} else {
				adj[n + 1].push_back(i);
				adj[i].push_back(n + 1);
			}
		}
		n++;
		for (int i = 1; i <= m; i++) {
			int u, v; cin >> u >> v;
			adj[u].push_back(v);
			adj[v].push_back(u);
		}

	}
	return 0;
}