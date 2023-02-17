#include <bits/stdc++.h>
using namespace std;

#define Fname ((string) "test")
#define int long long
#define ii pair <int, int>
#define iii pair <int, ii>
#define fi first
#define se second
#define endl '\n'
const int M = 998244353;
const int N = 505;

int n, x, P[N][N], f[N][N], C[N][N], res;

int Pow(int n, int k) {
	if (k < 2)
		return (k == 1 ? n : 1);
	int tmp = Pow(n, k / 2);
	(tmp *= tmp) %= M;
	return (k & 1 ? tmp * n % M : tmp);
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
		cin >> n >> x;
		f[n][0] = 1;
		C[0][0] = 1;
		for (int i = 1; i <= n; i++) 
			for (int j = 0; j <= n; j++) {
				if (j <= i) {
					if (j == 0)
						C[i][j] = 1;
					else
						C[i][j] = (C[i - 1][j - 1] + C[i - 1][j]) % M;
				}
				P[i][j] = Pow(i, j);
			}
		for (int i = n; i > 1; i--)
			for (int j = 0; j < x; j++)
				if (f[i][j]) 
					for (int k = i; k >= 0; k--)
						(f[k][min(x, i + j - 1)] += (f[i][j] * C[i][i - k]) % M * P[min(x, i + j - 1) - j][i - k]) %= M;
		for (int j = 1; j <= x; j++) 
			(res += f[0][j]) %= M;
		cout << res;
	}

	return 0;
}