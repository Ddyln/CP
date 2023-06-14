#include <bits/stdc++.h>
using namespace std;

#define int long long
const int N = 1e6 + 5;
const int MOD = 1e9 + 7;

int n, a[N], f[N], p2[N], pSum[N];

int GetSum(int i, int j) {
    return pSum[j] - pSum[i - 1];
}

signed main() {
    ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	freopen("test.inp", "r", stdin);
	freopen("test.ans", "w", stdout);
	cin >> n;
	p2[0] = 1;
    pSum[0] = 0;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		p2[i] = p2[i - 1] * 2 % MOD;
        pSum[i] = pSum[i - 1] + a[i];
	}

    f[0] = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = i; j > 0; j--)
            f[i] += f[j - 1] + GetSum(j, i) * (i - j + 1) * p2[max(0LL, j - 2)];
    }
    cout << f[n];
    return 0;
}