#include <bits/stdc++.h>
using namespace std;

#define Fname ((string) "test")
#define int long long
#define ii pair <int, int>
#define iii pair <int, ii>
#define fi first
#define se second
#define endl '\n'

const int N = 1e6 + 5;

int n, m, x[N];
bool vis[N];
vector <int> a[N], reg;

int dfs(int u) {
    vis[u] = 1;
    int res = x[u];
    for (int v : a[u])
        if (!vis[v]) 
            res = min(res, dfs(v));
    return res;
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
        for (int i = 1; i <= n; i++)
            cin >> x[i];
        for (int i = 1; i <= m; i++) {
            int u, v; cin >> u >> v;
            a[u].push_back(v);
            a[v].push_back(u);
        }
        for (int i = 1; i <= n; i++)
            if (!vis[i]) 
                reg.push_back(dfs(i));
        sort(reg.begin(), reg.end());
        int res = reg[0] * (reg.size() - 1);
        for (int i = 1; i < reg.size(); i++)
            res += reg[i];
        cout << res;
	}
	
	return 0;
}