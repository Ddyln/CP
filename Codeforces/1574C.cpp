#include <bits/stdc++.h>
using namespace std;

#define int long long
#define endl '\n'

const int N = 2e5 + 5;

int n, m, a[N], total;

signed main() {
    #ifdef lan_ngu
        freopen("test.inp", "r", stdin);
        freopen("test.out", "w", stdout);
    #endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        total += a[i];
    }
    sort(a + 1, a + 1 + n);
    cin >> m;
    for (int i = 1; i <= m; i++) {
        int atk, def;
        cin >> def >> atk;
        if (a[n] < def)
            cout << def - a[n] + max(0LL, atk - (total - a[n]));
        else {
            int k = lower_bound(a + 1, a + 1 + n, def) - a;
            int res = max(0LL, atk - (total - a[k]));
            if (k == 1)
                cout << res;
            else 
                cout << min(res, def - a[k - 1] + max(0LL, atk - (total - a[k - 1])));
        }
        cout << endl;
    }
    return 0;
}