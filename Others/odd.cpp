#include <bits/stdc++.h>
using namespace std;

const int N = 1e6;
int n, a[N];

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    #ifdef lan_ngu
        freopen("test.inp", "r", stdin);
        freopen("test.out", "w", stdout);
    #endif
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> a[i];
    vector <int> ans;
    for (int i = 0; i < n; i++)
        if (a[i] % 2 == 1)
            ans.push_back(a[i]);
    for (int i = 0; i < n; i++)
        if (a[i] % 2 == 0)
            ans.push_back(a[i]);
    for (int i = 0; i < n; i++)
        cout << ans[i] << ' ';
    return 0;
}