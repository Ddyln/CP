#include <bits/stdc++.h>
using namespace std;

const long long INF = 1e15;

struct dsu {
	std::vector<int> p;

	dsu(int n) : p(n, -1) {}

	int size(int x) {
		return -p[find(x)];
	}

	int find(int x) {
		return (p[x] < 0 ? x : p[x] = find(p[x]));
	}

	bool merge(int x, int y) {
		x = find(x);
		y = find(y);
		if (x == y) {
			return 0;
		}
		if (p[x] > p[y]) {
			std::swap(x, y);
		}
		p[x] += p[y];
		p[y] = x;
		return 1;
	}
};

int main() {
	freopen("sc3.inp", "r", stdin);
	freopen("sc3.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	int tt;
	cin >> tt;
	while (tt--) {
		int n, q;
		cin >> n >> q;
		vector<long long> a(n, INF);
		dsu d(n);
		map<pair<int, int>, int> mp;
		vector<vector<int>> adj(n);
		set<int> vis;
		while (q--) {
			char op;
			cin >> op;
			if (op == '!') {
				int u, v;
				long long w;
				cin >> u >> v >> w;
				u--;
				v--;
				mp[{u, v}] = w;
				mp[{v, u}] = -w;
				if (a[u] == INF && a[v] == INF) {
					a[u] = w;
					a[v] = 0;
					d.merge(u, v);
				} else if (a[u] == INF) {
					a[u] = a[v] + w;
					d.merge(u, v);
				} else if (a[v] == INF) {
					a[v] = a[u] - w;
					d.merge(u, v);
				} else {
					if (a[u] - a[v] == w && d.find(u) == d.find(v)) {
						// nothing...
					} else if (a[u] - a[v] == w) {
						d.merge(u, v);
					} else {
						vis.clear();
						function<void(int, int)> dfs = [&](int x, int p) {
							vis.insert(x);
							a[x] = mp[{x, p}] + a[p];
							for (int y : adj[x]) {
								if (!vis.count(y)) {
									dfs(y, x);
								}
							}
						};
						if (d.size(u) < d.size(v)) {
							dfs(u, v);
						} else {
							dfs(v, u);
						}
						d.merge(u, v);
					}
				}
				adj[u].emplace_back(v);
				adj[v].emplace_back(u);
			} else {
				int u, v;
				cin >> u >> v;
				u--;
				v--;
				if (a[u] == INF || a[v] == INF || d.find(u) != d.find(v)) {
					cout << "UNKNOWN" << '\n';
				} else {
					cout << a[u] - a[v] << '\n';
				}
			}
		}
	}
	return 0;
}