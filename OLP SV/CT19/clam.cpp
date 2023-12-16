#include <bits/stdc++.h>
using namespace std;

const int N = 1003;
const int INF = 1e9;
#define endl '\n'

int a[N][N], m, n, q, k, c, stMin[N][4 * N], stSum[N][4 * N], res, lazy[N][4 * N];

void Down(int id, int l, int r, int row) {
    if (lazy[row][id]) {
        lazy[row][id * 2] = lazy[row][id];
        lazy[row][id * 2 + 1] = lazy[row][id];
        int m = (l + r) / 2;
        stSum[row][id * 2] = lazy[row][id] * (m - l + 1);
        stSum[row][id * 2 + 1] = lazy[row][id] * (r - m);
        stMin[row][id * 2] = lazy[row][id];
        stMin[row][id * 2 + 1] = lazy[row][id];
    }
    lazy[row][id] = 0;
}

int GetMin(int id, int l, int r, int u, int v, int row) {
    if (r < u || l > v)
        return INF;
    if (l >= u && r <= v)
        return stMin[row][id];
    Down(id, l, r, row);
    int m = (l + r) / 2;
    return min(GetMin(id * 2, l, m, u, v, row), GetMin(id * 2 + 1, m + 1, r, u, v, row));
}

int GetSum(int id, int l, int r, int u, int v, int row) {
    if (r < u || l > v)
        return 0;
    if (l >= u && r <= v)
        return stSum[row][id];
    Down(id, l, r, row);
    int m = (l + r) / 2;
    return GetSum(id * 2, l, m, u, v, row) + GetSum(id * 2 + 1, m + 1, r, u, v, row);
}

void Update(int id, int l, int r, int u, int v, int k, int row) {
    if (r < u || l > v)
        return;
    if (l >= u && r <= v) {
        stMin[row][id] = k;
        stSum[row][id] = k * (r - l + 1);
        lazy[row][id] = k;
        return;
    }
    Down(id, l, r, row);
    int m = (l + r) / 2;
    Update(id * 2, l, m, u, v, k, row);    
    Update(id * 2 + 1, m + 1, r, u, v, k, row);    
    stSum[row][id] = stSum[row][id * 2] + stSum[row][id * 2 + 1];
    stMin[row][id] = min(stMin[row][id * 2], stMin[row][id * 2 + 1]);
}

bool check(int row, int l, int r) {
    return (res + GetSum(1, 1, n, l, r, row) - (r - l + 1) * k <= c);
}

int cnpLR(int row, int l, int r, int i) {
    if (l == r)
        return l;
    int m = (l + r + 1) / 2;
    if (check(row, i, m))
        return cnpLR(row, m, r, i);
    return cnpLR(row, l, m - 1, i);
}

int cnpRL(int row, int l, int r, int i) {
    if (l == r)
        return l;
    int m = (l + r) / 2;
    if (check(row, m, i))
        return cnpRL(row, l, m, i);
    return cnpRL(row, m + 1, r, i);
}

void Build(int id, int l, int r, int row) {
    if (l == r) {
        stMin[row][id] = a[row][l];
        stSum[row][id] = a[row][l];
        return;
    }
    int m = (l + r) / 2;
    Build(id * 2, l, m, row);
    Build(id * 2 + 1, m + 1, r, row);
    stSum[row][id] = stSum[row][id * 2] + stSum[row][id * 2 + 1];
    stMin[row][id] = min(stMin[row][id * 2], stMin[row][id * 2 + 1]);
}

signed main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    #ifdef lan_ngu
        freopen("test.inp", "r", stdin);
        freopen("test.out", "w", stdout);
    #endif
    cin >> m >> n;
    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) 
            cin >> a[i][j];  
        Build(1, 1, n, i);
    }
    cin >> q >> k;
    while (q--) {
        int t = 0; cin >> t;
        if (t == 1) {
            int i1, j1, i2, j2;
            cin >> c >> j1 >> i1 >> j2 >> i2;
            res = 0;
            bool ok = 1;
            for (int i = i1; ok && i <= i2; i++) 
                if (GetMin(1, 1, n, j1, j2, i) < k)
                    ok = 0;
            for (int i = i1; ok && i <= i2; i++) {
                if ((i - i1) % 2 == 0) {
                    // l -> r
                    int p = cnpLR(i, j1 - 1, j2, j1);
                    if (p < j2) {
                        if (res < c) {
                            if (p >= j1) {
                                res += GetSum(1, 1, n, j1, p, i) - (p - j1 + 1) * k;
                                Update(1, 1, n, j1, p, k, i);
                            }
                            Update(1, 1, n, p + 1, p + 1, GetSum(1, 1, n, p + 1, p + 1, i) - (c - res), i);
                            res = c;                            
                        }
                        break;
                    }
                    res += GetSum(1, 1, n, j1, p, i) - (p - j1 + 1) * k;
                    Update(1, 1, n, j1, p, k, i);
                }
                else {
                    // r -> l
                    int p = cnpRL(i, j1, j2 + 1, j2);
                    if (p > j1) {
                        if (res < c) {
                            if (p <= j2) {
                                res += GetSum(1, 1, n, p, j2, i) - (j2 - p + 1) * k;
                                Update(1, 1, n, p, j2, k, i);
                            }
                            Update(1, 1, n, p - 1, p - 1, GetSum(1, 1, n, p - 1, p - 1, i) - (c - res), i);
                            res = c;
                        }
                        break;
                    }
                    res += GetSum(1, 1, n, p, j2, i) - (j2 - p + 1) * k;
                    Update(1, 1, n, p, j2, k, i);
                }
            }
            cout << res << endl;
        }
        else cin >> k;
    }
    return 0;
}