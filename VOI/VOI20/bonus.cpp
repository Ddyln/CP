#include <bits/stdc++.h>
using namespace std;

#define Fname ((string) "test")
#define int long long
#define ii pair <int, int>
#define iii pair <int, ii>
#define fi first
#define se second
#define endl '\n'
const int N = 305;

int n, m, a[N], f[N][N][N];

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
			cin >> a[i];
		for (int i = n - 1; i > 0; i--)	
			for (int j = i + 1; j <= n; j++)
				for (int k = 1; k <= min((j - i + 1) / 2, m); k++) 
					f[i][j][k] = max({f[i + 2][j][k - 1] + abs(a[i] - a[i + 1]),
									f[i][j - 2][k - 1] + abs(a[j] - a[j - 1]),
									f[i + 1][j - 1][k - 1] + abs(a[i] - a[j]),
									f[i + 1][j][k], f[i][j - 1][k]});
		cout << f[1][n][m];
	}

	return 0;
}