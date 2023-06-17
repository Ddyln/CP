#include <bits/stdc++.h>
using namespace std;
const int MOD = 1e9 + 7;
const int N = 25;
int n, m, b[N], s[N], res = 0;

void Try(int i, int beauty, int strength) {
    if (i == n) {
        res = max(res, beauty);
    }
    else {
        Try(i + 1, beauty, strength);
        if (strength >= s[i])
            Try(i + 1, (beauty + b[i]) % MOD, strength - s[i]);
    }
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    #ifdef lan_ngu
        freopen("test.inp", "r", stdin);
        freopen("test.out", "w", stdout);
    #endif
    cin >> m >> n;
    for (int i = 0; i < n; i++)
        cin >> s[i] >> b[i];
    Try(0, 0, m);
    cout << res;
    return 0;
}