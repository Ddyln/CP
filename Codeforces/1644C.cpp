#include <bits/stdc++.h>
using namespace std;

#define Fname ((string) "test")
#define int long long
#define ii pair <int, int>
#define iii pair <int, ii>
#define fi first
#define se second
#define endl '\n'
const int N = 5005;

int n, x, a[N], f[N][N];

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
		cin >> n >> x;
		for (int i = 1; i <= n; i++) {
			cin >> a[i];
			for (int j = 0; j <= n; j++)
				f[i][j] = 0;
		}
		for (int i = 1; i <= n; i++)
			for (int j = 0; j <= n; j++) {
				if (j > 0) 
					f[i][j] = max({0LL, f[i][j - 1], max(0LL, f[i - 1][j]) + a[i], max(0LL, f[i - 1][j - 1]) + a[i] + x});
				else
					f[i][j] = max(f[i - 1][j] + a[i], a[i]);
			}
		for (int i = 0; i <= n; i++) {
			int res = 0;
			for (int j = 1; j <= n; j++) 
				res = max(res, f[j][i]);
			cout << res << ' ';
		}
		cout << endl;
	}

	return 0;
}