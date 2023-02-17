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

int n, m, k, cur, ans[N], deg[N];
vector <ii> a[N], E;
bool er[N];
queue <int> q;

void erase(int u) {
	q.push(u);
	while (q.size()) {
		u = q.front();
		q.pop();
		cur--;
		deg[u] = -1;
		for (ii tmp : a[u]) { 
			int id = tmp.fi, v = tmp.se;
			if (er[id])
				continue;
			er[id] = 1;
			if (deg[v] >= k && --deg[v] < k)
				q.push(v);
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
			int u, v; cin >> u >> v;
			a[u].push_back(ii(i - 1, v));
			a[v].push_back(ii(i - 1, u));
			E.push_back(ii(u, v));
		}
		cur = n;
		for (int i = 1; i <= n; i++)
			deg[i] = a[i].size();
		for (int i = 1; i <= n; i++)
			if (deg[i] < k && deg[i] != -1)
				erase(i);
		for (int i = m - 1; i >= 0; i--) {
			int u = E[i].fi, v = E[i].se;
			ans[m - i - 1] = cur;
			if (deg[u] > deg[v])
				swap(u, v);
			if (er[i])
				continue;
			if (--deg[u] == k - 1)
				erase(u);
			else
				deg[v]--;
			er[i] = 1;
		}
		while (m--)
			cout << ans[m] << endl;
	}

	return 0;
}