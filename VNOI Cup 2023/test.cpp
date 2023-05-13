#include <bits/stdc++.h>
using namespace std;

#define int long long
const int N = 1e5 + 3;

int n, k, a[N], sum[N], cnt[N][26][2], f[N][105];
string s, t;

int getSum(int l, int r) {
    return sum[r] - sum[l - 1];
}

bool ok(int l, int r) {
    for (int i = 0; i < 26; i++)
        if (cnt[r][i][0] - cnt[l - 1][i][0] != cnt[r][i][1] - cnt[l - 1][i][1])
            return 0;
    return 1;
}

signed main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    freopen("test.inp", "r", stdin);
    int _t = 1;
    // int _t; cin >> _t;
    while (_t--) {
        cin >> n >> k >> s >> t;
        s = " " + s;
        t = " " + t;
        for (int i = 1; i <= n; i++) {
            cin >> a[i];
            sum[i] = sum[i - 1] + a[i];
            for (int j = 0; j < 26; j++) {
                cnt[i][j][0] = cnt[i - 1][j][0];
                cnt[i][j][1] = cnt[i - 1][j][1];
            }
            cnt[i][s[i] - 'a'][0]++;
            cnt[i][t[i] - 'a'][1]++;
        }
        for (int i = 1; i <= n; i++)
            for (int j = 0; j <= k; j++)
                f[i][j] = 1e17;
        for (int i = 1; i <= n; i++)
            if (s[i] != t[i])
                break;
            else
                f[i][0] = 0;
        f[0][0] = 0;
        for (int i = 1; i <= n; i++) 
            if (ok(1, i)) {
                for (int j = 1; j <= k; j++) {
                    f[i][j] = getSum(1, i);
                    if (s[i] == t[i] && ok(1, i - 1))
                        f[i][j] = min(f[i][j], f[i - 1][j]);
                    for (int l = i - 1; l > 0; l--)
                        if (ok(1, l - 1) && ok(l, i)) {
                            f[i][j] = min(f[i][j], f[l - 1][j - 1] + getSum(l, i));
                        }
                }
            }
        cout << f[n][k];
    }
    return 0;
}