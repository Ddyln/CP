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

int n, num[2][N], mem[2][N], res, tmp, gr;
bool vis[2][N];
vector <ii> a[N];
stack <int> st;

void dfs(int u, int val) {
	vis[val][u] = 1;
	mem[val][u] = gr;
	tmp++;
	for (ii tmp : a[u]) {
		int v = tmp.se, w = tmp.fi;
		if (w != val || vis[val][v])
			continue;
		dfs(v, val);
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
		cin >> n;
		for (int i = 1; i < n; i++) {
			int u, v, w; cin >> u >> v >> w;
			a[u].push_back({w, v});
			a[v].push_back({w, u});
		}
		for (int val = 0; val < 2; val++) {
			gr = 0;
			for (int i = 1; i <= n; i++)
				if (!vis[val][i]) {
					tmp = 0;
					gr++;
					dfs(i, val);
					res += tmp * (tmp - 1);
					num[val][gr] = --tmp;
				}
		}
		for (int i = 1; i <= n; i++)
			res += num[0][mem[0][i]] * num[1][mem[1][i]];
		cout << res;
	}

	return 0;
}