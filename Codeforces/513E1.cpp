#include <bits/stdc++.h>
using namespace std;

#define Fname ((string) "test")
#define int long long
#define ii pair <int, int>
#define iii pair <int, ii>
#define fi first
#define se secondi
#define endl '\n'
const int N = 405;

int n, f[N][55][N], pre[N], res, g;

signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	#ifndef ONLINE_JUDGE
		freopen((Fname + ".inp").c_str(), "r", stdin);
		freopen((Fname + ".out").c_str(), "w", stdout);
	#endif

	// int _nt; cin >> _nt;
	int _nt = 1;
	while (_nt--) {
		cin >> n >> g;
		for (int i = 1; i <= n; i++) {
			int a; cin >> a;
			pre[i] = pre[i - 1] + a;
		}	
		for (int i = 2; i <= n; i++)
			for (int j = 2; j <= min(g, i); j++)
				for (int k = 1; i - k >= j - 1; k++)
					for (int l = 1; l <= i - k; l++)
						if (i - k - l >= j - 2)
							f[i][j][k] = max(f[i][j][k], f[i - k][j - 1][l] + abs(pre[i] - pre[i - k] - (pre[i - k] - pre[i - k - l])));
		// cerr << f[4][2][3];
		for (int i = 1; i <= n; i++)
			res = max(res, f[n][g][i]);
		cout << res;
	}

	return 0;
}