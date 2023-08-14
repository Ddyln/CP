#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;

int n, m, l[N], r[N], q, x[N], res, a[N];

void reset() {
    for (int i = 1; i <= n; i++)
        a[i] = 0;
}

int get(int l, int r) {
    return a[r] - a[l - 1];
}

int len(int l, int r) {
    return r - l + 1;
}

bool check(int k) {
    reset();
    for (int i = 1; i <= k; i++)
        a[x[i]] = 1;
    for (int i = 1; i <= n; i++)
        a[i] += a[i - 1];
    for (int i = 1; i <= m; i++)
        if (get(l[i], r[i]) > len(l[i], r[i]) / 2)
            return 1;
    return 0;
}

int cnp(int l, int r) {
    if (l == r)
        return l;
    int mid = (l + r) / 2;
    if (check(mid))
        return cnp(l, mid);
    return cnp(mid + 1, r);
}

signed main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    #ifdef lan_ngu
    freopen("test.inp", "r", stdin);
    freopen("test.out", "w", stdout);
    #endif
    int _nt; cin >> _nt;

    while (_nt--) {
        cin >> n >> m;
        for (int i = 1; i <= m; i++)
            cin >> l[i] >> r[i];
        cin >> q;
        for (int i = 1; i <= q; i++)
            cin >> x[i];     
        cout << ((res = cnp(1, q + 1)) == q + 1 ? -1 : res) << endl;      
    }
    return 0;
}