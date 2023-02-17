#include <bits/stdc++.h>
using namespace std;

#define Fname ((string) "test")
#define int long long
#define ii pair <int, int>
#define iii pair <int, ii>
#define fi first
#define se second
#define endl '\n'
const int N = 205;

int n, a[N], f[N][N][N], d, res;

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
		cin >> n >> d;
		n *= 2;
		for (int i = 1; i <= n; i++)
			cin >> a[i];
		for (int k = 1; k < n; k++) {
			for (int i = 1; i <= k; i++)
				for (int j = k + 1; j <= n; j++)
					if (abs(a[i] - a[j]) <= d)
						f[k][i][j] = f[k][i - 1][j - 1] + 1;
					else
						f[k][i][j] = max(f[k][i - 1][j], f[k][i][j - 1]);
			res = max(res, f[k][k][n]);
		}
		cout << res;
	}

	return 0;
}