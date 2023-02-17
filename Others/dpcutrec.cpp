#include <bits/stdc++.h>
using namespace std;

#define Fname ((string) "test")
#define int long long
#define ii pair <int, int>
#define iii pair <int, ii>
#define fi first
#define se second
#define endl '\n'

const int N = 1003;

int n, m, f[N][N];

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
		if (n > m)
			swap(n, m);
		for (int i = 1; i <= n; i++)
			for (int j = i; j <= m; j++) {
				f[i][j] = i * j;
				if (i == j)
					f[i][j] = 1;
				for (int k = 1; k <= i; k++)
					f[i][j] = min({f[i][j], 1 + f[i - k][k] + f[i][j - k], f[i - k][j] + f[k][j - k] + 1});
				f[j][i] = f[i][j];
			}
		cout << f[n][m];
	}
	
	return 0;
}