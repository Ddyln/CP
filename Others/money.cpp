#include <bits/stdc++.h>
using namespace std;

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    #ifdef lan_ngu
        freopen("test.inp", "r", stdin);
        freopen("test.out", "w", stdout);
    #endif
    int m, a[] = {0, 1, 2, 5, 10, 20, 50, 100, 200, 500}, f[14][1000] = {0};
    cin >> m;
    if (m < 1000 || m % 1000 != 0) {
        cout << 0;
        return 0;
    }
    m /= 1000;

    for (int i = 0; i < 10; i++)
        f[i][0] = 1;
    for (int i = 1; i < 10; i++)
        for (int j = 1; j <= m; j++) {
            f[i][j] = f[i - 1][j];
            if (j >= a[i]) 
                f[i][j] += f[i][j - a[i]];
        }
    cout << f[9][m];
    return 0;
}