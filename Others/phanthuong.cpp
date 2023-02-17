#include <bits/stdc++.h>
using namespace std;

#define int long long
#define endl '\n'

const int N = 1e5 + 5;

int n, k, a[N], sum[N], pre[N], suf[N], res;

signed main() {
    freopen("test.inp", "r", stdin);
    cin >> n >> k;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        sum[i] = sum[i - 1] + a[i];
    }
    pre[k] = sum[k];
    suf[n - k + 1] = sum[n] - sum[n - k];
    for (int i = k + 1; i <= n; i++) 
        pre[i] = max({pre[i - k], sum[i] - sum[i - k], pre[i - 1]});
    for (int i = n - k; i > 0; i--) 
        suf[i] = max({suf[i + k], sum[i + k - 1] - sum[i - 1], suf[i + 1]});

    for (int i = 0; i < k; i++)
        pre[i] = 1e18;
    for (int i = n - k + 2; i <= n + 1; i++)
        suf[i] = 1e18;
        
    res = 1e18;
    for (int i = k; i <= n; i++) {
        if (sum[i] - sum[i - k] >= max(pre[i - k], suf[i + 1]))
            res = min(res, sum[i] - sum[i - k]);
    }
    cout << res;
    return 0;
}