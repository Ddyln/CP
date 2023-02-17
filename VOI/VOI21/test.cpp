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

int n, k, _l, _r, pre[5][N], sum[N][5][N], f[N][5][N], res;
vector <int> a[N];

void dfs(int u, int par) {
	sum[u][1][0] = f[u][1][0] = 1;
	for (int v : a[u])
		if (v != par) {
			dfs(v, u);
			for (int j = 1; j <= k; j++) {
				for (int l = 1; l <= _r; l++) {
					if (j < k)
						f[u][j][l] += f[v][j][l - 1] + f[v][j - 1][l - 1];
					else
						f[u][j][l] += f[v][j - 1][l - 1];
				}
			}
		}
	for (int j = 1; j <= k; j++)
		for (int l = 1; l <= _r; l++)
			sum[u][j][l] = sum[u][j][l - 1] + f[u][j][l];
	for (int i = _l; i <= _r; i++)
		res += f[u][k][i];
	memset(pre, 0, sizeof(pre));
	for (int v : a[u])
		if (v != par)
		for (int j = 1; j <= k; j++)
			for (int l = 0; l <= _r; l++)
				pre[j][l] += sum[v][j][l];
	for (int v : a[u])
		if (v != par) {
			for (int j = 1; j <= k; j++)
				for (int l = 0; l <= _r; l++)
					pre[j][l] -= sum[v][j][l];
			for (int j = 1; j < k; j++)
				for (int l = 0; l < _r; l++) {
					if (_l - (l + 2) > 0) {
						res += f[v][j][l] * (pre[k - j][_r - (l + 2)] - pre[k - j][_l - (l + 2) - 1]);
						if (k - j - 1 > 0) {
							res += f[v][j][l] * (pre[k - j - 1][_r - (l + 2)] - pre[k - j - 1][_l - (l + 2) - 1]);
						}
					} else {
						res += f[v][j][l] * (pre[k - j][_r - (l + 2)]);
						if (k - j - 1 > 0) {
							res += f[v][j][l] * (pre[k - j - 1][_r - (l + 2)]);
						}
					}
				}
		}
	// cerr << u << ' ' << res << endl;
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