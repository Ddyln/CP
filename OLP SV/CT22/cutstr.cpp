#include <bits/stdc++.h>
using namespace std;

#define int long long
const int MOD = 1e9 + 7;
const int P = 31;
const int N = 1e4 + 5;

int k, n, h[N][2], p[N], l[N], f[202][8195];
string s;

int GetHash(int i, int j) {
    return (h[j][0] - h[i - 1][0] * p[j - i + 1] + MOD * MOD) % MOD;
}

int GetRevHash(int i, int j) {
    return (h[i][1] - h[j + 1][1] * p[j - i + 1] + MOD * MOD) % MOD;
}

bool IsPalind(int i, int j) {
    return (j <= n && GetHash(i, j) == GetRevHash(i, j));
}

signed main() {
    #ifdef lan_ngu
        freopen("test.inp", "r", stdin);
        freopen("test.out", "w", stdout);
    #endif
    ios_base::sync_with_stdio(false); cin.tie(NULL);

    cin >> s >> k;
    n = s.size();
    s = " " + s;
    for (int i = 1; i <= n; i++)
        h[i][0] = (h[i - 1][0] * P + (int)s[i]) % MOD;
    for (int i = n; i > 0; i--)
        h[i][1] = (h[i + 1][1] * P + (int)s[i]) % MOD;

    p[0] = 1;
    for (int i = 1; i <= 10000; i++)
        p[i] = p[i - 1] * P % MOD;

    while (k--) {
        int m;
        cin >> m;
        if (m == 1) {
            cin >> l[1];
            bool ok = 0;
            for (int i = l[1]; i <= n; i++)
                if (IsPalind(i - l[1] + 1, i)) {
                    ok = 1;
                    break;
                }        
            cout << (ok ? "YES\n" : "NO\n");
            continue;
        }
        f[0][0] = 1;
        for (int i = 0; i < m; i++)
            cin >> l[i];
        int M = (1 << m);
        for (int i = 0; i < n; i++)
            for (int mask = 0; mask < M; mask++)
                if (f[i][mask]) {
                    f[i + 1][mask] = f[i][mask];
                    for (int j = 0; j < m; j++)
                        if (!(mask & (1 << j))) {
                            if (IsPalind(i + 1, i + l[j]))
                                f[i + l[j]][mask | (1 << j)] = f[i][mask];
                        }
                }
        cout << (f[n][--M] ? "YES\n" : "NO\n");
        if (k)
            for (int i = 0; i < n; i++)
                for (int mask = 0; mask < M; mask++)
                    f[i][mask] = 0;
    }
    return 0;
}