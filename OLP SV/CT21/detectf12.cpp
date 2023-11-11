#include <bits/stdc++.h>
using namespace std;

#define int long long
const int N = 1003;
int n, f0, d, x[N], y[N], res[2], h[N];
vector <int> a[N];

int distSquare(int i, int j) {
    return (x[i] - x[j]) * (x[i] - x[j]) + (y[i] - y[j]) * (y[i] - y[j]);
}

signed main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    #ifdef lan_ngu
    freopen("test.inp", "r", stdin);
    freopen("test.out", "w", stdout);
    #endif

    cin >> n >> f0 >> d;
    for (int i = 1; i <= n; i++) {
        cin >> x[i] >> y[i];
        h[i] = -1;
    }
    
    h[f0] = 0;
    for (int i = 1; i < n; i++)
        for (int j = i + 1; j <= n; j++)
            if (distSquare(i, j) < d * d)
                a[i].push_back(j), a[j].push_back(i);
    
    queue <int> q;
    q.push(f0);
    while (q.size()) {
        int u = q.front();
        q.pop();
        if (h[u] && h[u] < 3)
            res[h[u] - 1]++;
        for (int v : a[u])
            if (!(~h[v])) {
                h[v] = h[u] + 1;
                q.push(v);
            }
    }
    cout << res[0] << ' ' << res[1];
    return 0;
}