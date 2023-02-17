#include <bits/stdc++.h>
using namespace std;

#define Fname ((string) "test")
// #define int long long
#define ii pair <int, int>
#define iii pair <int, ii>
#define fi first
#define se second
#define endl '\n'
const int N = 1005;

int n, k, M, cost[N], c[N], v[N], res;

signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	#ifdef lan_ngu
		freopen((Fname + ".inp").c_str(), "r", stdin);
		freopen((Fname + ".out").c_str(), "w", stdout);
	#endif

	for (int i = 1; i <= 1000; i++) 
		for (int j = 1; j <= i; j++) 
			if (i + i / j <= 1000)
				cost[i + i / j] = (!cost[i + i / j] ? cost[i] + 1 : min(cost[i + i / j], cost[i] + 1));

	int _nt; cin >> _nt;
	// int _nt = 1;
	while (_nt--) {
		cin >> n >> k;
		M = 0;
		for (int i = 1; i <= n; i++) {
			int b; cin >> b;
			c[i] = cost[b];
			M += c[i];
		}
		k = min(k, M);
		vector <vector <int>> f;
		f.resize(n + 1);
		for (int i = 0; i <= n; i++)
			f[i].resize(k + 1);
		for (int i = 1; i <= n; i++)
			cin >> v[i];
		res = 0;
		for (int i = 1; i <= n; i++)
			for (int j = 0; j <= k; j++) {
				if (c[i] <= j)
					f[i][j] = max(f[i - 1][j], f[i - 1][j - c[i]] + v[i]);
				else
					f[i][j] = f[i - 1][j];
				res = max(res, f[i][j]);
			}
		cout << res << endl;
	}

	return 0;
}