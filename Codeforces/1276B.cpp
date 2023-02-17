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

int n, m, cnt, a, b, connect[N], mem[N], tmp[4];
bool vis[N];
vector <int> g[N];

void dfs(int u) {
	vis[u] = 1;
	mem[cnt]++;
	for (int v : g[u]) 
		if (!vis[v]) {
			dfs(v);
		} else if (v == a)
			connect[cnt] |= 1;
		else if (v == b)
			connect[cnt] |= 2;
}

// case 177th test 3, n = 30000

signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	#ifdef lan_ngu
		freopen((Fname + ".inp").c_str(), "r", stdin);
		freopen((Fname + ".out").c_str(), "w", stdout);
	#endif

	int _nt; cin >> _nt;
	// int _nt = 1;
	while (_nt--) {
		cin >> n >> m >> a >> b;
		for (int i = 1; i <= n; i++) {
			vis[i] = (i == a || i == b);
			g[i].clear();
		}
		cnt = 0;
		connect[1] = connect[2] = connect[3] = 0;
		mem[1] = mem[2] = mem[3] = 0;
		for (int i = 1; i <= m; i++) {
			int u, v; cin >> u >> v;
			g[u].push_back(v);
			g[v].push_back(u);
		}
		for (int i = 1; i <= n; i++)
			if (!vis[i]) {
				cnt++;
				dfs(i);
			}
		int ok = 0;
		tmp[1] = tmp[2] = tmp[3] = 0;
		for (int i = 1; i <= cnt; i++)
			tmp[connect[i]] += mem[i];
		cout << tmp[1] * tmp[2] << endl;
	}
	
	return 0;
}