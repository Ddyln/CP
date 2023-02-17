#include <bits/stdc++.h>
using namespace std;

#define Fname ((string) "test")
#define ii pair <int, int>
#define iii pair <int, ii>
#define fi first
#define se second
#define endl '\n'
const int N = 2e5 + 5;

int n, dep[N];
long long f[N][3], res;
vector <int> a[N];

bool isLeaf(int u) {
	return (u != 1 && a[u].size() == 1);
}

void dfs(int u, int par) {
	if (isLeaf(u))
		f[u][1] = N;
	f[u][0] = 1;
	for (int v : a[u])
		if (v != par) {
			dep[v] = dep[u] + 1;
			dfs(v, u);
			if (dep[u] > 2) {
				f[u][0] += min({f[v][0], f[v][1], f[v][2]});
				if (f[u][1] == 0)
					f[u][1] = f[u][2] + f[v][0];
				else
					f[u][1] = min(f[u][1] + min(f[v][0], f[v][1]), f[u][2] + f[v][0]);
				f[u][2] += f[v][1];
			}
		}
	if (dep[u] == 3)
		res += min({f[u][0], f[u][1], f[u][2]});
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
		cin >> n;
		for (int i = 1; i < n; i++) {
			int u, v; cin >> u >> v;
			a[u].push_back(v);
			a[v].push_back(u);
		}
		dep[1] = 1;
		dfs(1, 1);
		cout << res;
	}

	return 0;
}