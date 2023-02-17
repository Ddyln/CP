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
const int M = 1e9 + 7;
const int MASK = (1 << 20) + 5;

int n, a[MASK], k, l, r, f[N][N][256], res, cnt[20], ft[MASK], dp[MASK];
bool have[20];

int Pow(int n, int k) {
	if (k < 2)
		return (k == 1 ? n : 1);
	int tmp = Pow(n, k / 2);
	tmp = tmp * tmp % M;
	return (k & 1 ? tmp * n % M : tmp);
}

int C(int n, int k) {
	if (k > n)
		return 0;
	if (k == 0)
		return 1;
	int res = ft[n];
	res = res * Pow(ft[k], M - 2) % M;
	res = res * Pow(ft[n - k], M - 2) % M;
	return res;
}

signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	#ifdef lan_ngu
		freopen((Fname + ".inp").c_str(), "r", stdin);
		freopen((Fname + ".out").c_str(), "w", stdout);
	#endif
	ft[0] = 1;
	for (int i = 1; i <= 1000000; i++)
		ft[i] = ft[i - 1] * i % M;
	// int _nt; cin >> _nt;

	int _nt = 1;
	while (_nt--) {
		cin >> n >> k >> l >> r;
		for (int i = 1; i <= n; i++)
			cin >> a[i];
		if (n <= 200) {
			f[0][0][0] = 1;
			for (int i = 0; i < n; i++)
				for (int j = 0; j <= k; j++)
					for (int mask = 0; mask < 256; mask++)
						if (f[i][j][mask]) {
							int &cur = f[i][j][mask];
							f[i + 1][j][mask] += cur;
							f[i + 1][j + 1][mask | a[i + 1]] += cur;
						}
			for (int mask = l; mask <= r; mask++)
				if (mask % 3 == 0 && mask < 256)
					(res += f[n][k][mask]) %= M;
			cout << res;
		} else {
			r = __builtin_popcount(l);
			if (l % 3 != 0) {
				cout << 0;
				return 0;
			}
			for (int i = 1; i <= n; i++) 
				if ((l & a[i]) == a[i]) 
					dp[a[i]]++;
			int res = 0;
			for (int i = 0; i < 20; i++)
				for (int mask = 0; mask <= l; mask++)
					if (mask & (1 << i))
						(dp[mask] += dp[mask ^ (1 << i)]) %= M;
			for (int i = 0; i <= l; i++)
				dp[i] = C(dp[i], k);
			for (int mask = 0; mask <= l; mask++) 
				if ((mask & l) == mask) {
					if (abs(r - __builtin_popcount(mask)) % 2 == 0)
						(res += dp[mask]) %= M;
					else
						res = (res - dp[mask] + M) % M;
				}
			cout << res;
		}
	}

	return 0;
}