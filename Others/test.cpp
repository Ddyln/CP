#include <bits/stdc++.h>
using namespace std;

#define int long long
const int N = 1e6 + 5;
const int MOD = 1e9 + 7;

int n, a[N], p2[N], s1 = 0, s2 = 0, s3 = 0, s4 = 0, f_n = 0, pf = 0;

signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	freopen("test.inp", "r", stdin);
	freopen("test.out", "w", stdout);
	cin >> n;
	p2[0] = 1;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		p2[i] = p2[i - 1] * 2 % MOD;
	}
	for (int i = 1; i <= n; i++) {
		(s1 += p2[max(0LL, i - 2)]) %= MOD;
		(s3 += s1) %= MOD;
		(s4 += s2 + s3 * a[i] % MOD) %= MOD;
		f_n = (pf + s4) % MOD;
		(s2 += s1 * a[i] % MOD) %= MOD;
		(pf += f_n) %= MOD;
	}
	cout << f_n;
	return 0;
}