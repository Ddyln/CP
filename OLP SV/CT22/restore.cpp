#include <bits/stdc++.h>
using namespace std;

#define int long long
const int MOD = 1e9 + 7;
const int N = 5e3 + 3;

int f[N][100];

signed main() {
    #ifdef lan_ngu
        freopen("test.inp", "r", stdin);
        freopen("test.out", "w", stdout);
    #endif
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int m, k;
    cin >> m >> k;
    f[0][0] = 1;
    for (int i = 0; i < m; i++)
        for (int j = 0; j < k; j++)
            if (f[i][j]) {
                (f[i + 1][(j + 2) % k] += f[i][j] * 3) %= MOD;
                (f[i + 1][(j + 1) % k] += f[i][j] * 3) %= MOD;
                (f[i + 1][j] += f[i][j]) %= MOD;
            }
    cout << (f[m][0] - 1 + MOD) % MOD;
    return 0;
}