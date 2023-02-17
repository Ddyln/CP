#include <bits/stdc++.h>
using namespace std;

#define Fname ((string) "test")
#define ii pair <int, int>
#define iii pair <int, ii>
#define fi first
#define se second
#define endl '\n'
const int N = 1e6 + 5;
const int M = 1e9 + 7;

int n, f[N * 2], p2[N];
unsigned int a[N];

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
		cin >> n;
		p2[0] = 1;
		for (int i = 1; i <= max(20, n); i++) {
			if (i <= n) {
				cin >> a[i];
				a[i] = (((~a[i]) << 12) >> 12);
				f[a[i]]++;
			}
			p2[i] = p2[i - 1] * 2 % M;
		}

		for (int i = 0; i < 20; i++)
			for (int mask = 0; mask < p2[20]; mask++)
				if (mask & p2[i]) 
					f[mask] += f[mask ^ p2[i]];

		long long res = 0;
		for (int i = p2[20] - 1; i >= 0; i--)
			if ((20 - __builtin_popcount(i)) % 2)
				(res -= 1LL * p2[f[i]] - M) %= M;
			else
				(res += 1LL * p2[f[i]]) %= M;
		cout << res;
	}

	return 0;
}