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

int n, k, _l, _r, f[N][5][N], res, child[N];
vector <int> a[N];

void dfs(int u, int par) {
	child[u] = f[u][1][0] = f[u][0][0] = 1;
	for (int v : a[u])
		if (v != par) {
			dfs(v, u);
			child[u] += child[v];
			for (int uhave = k; uhave > 0; uhave--)
				for (int uEdge = child[u] - 1; uEdge > 0; uEdge--)
					for (int vhave = min(uhave, k - 1); vhave > 0; vhave--)
						for (int vEdge = min(child[v] - 1, uEdge - 1); vEdge >= 0; vEdge--)
							if (uEdge - vEdge > 0)
								f[u][uhave][uEdge] += f[u][uhave - vhave][uEdge - vEdge - 1] * f[v][vhave][vEdge];
		}
	for (int i = _l; i <= _r; i++)
		res += f[u][k][i];
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
		cin >> n >> k >> _l >> _r;
		for (int i = 1; i < n; i++) {
			int u, v; cin >> u >> v;
			a[u].push_back(v);
			a[v].push_back(u);
		}
		dfs(1, 1);
		cout << res;
	}

	return 0;
}