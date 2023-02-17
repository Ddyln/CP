#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define int long long
const int N = 5005;
const int INF = 1e16;

int n, res, W, c[N], d[N], f[N][N][2], tmp[N][2], child[N];
vector <int> a[N];

void dfs(int u) {
    f[u][1][0] = c[u];
    f[u][1][1] = d[u];
    int bigChild = 0;
    for (int v : a[u])
        if (child[v] > child[bigChild])
            bigChild = v;
    if (bigChild) {
        dfs(bigChild);
        for (int i = 1; i <= n; i++) {
            f[u][i][0] = min({f[u][i][0], f[bigChild][i][0], f[bigChild][i - 1][0] + c[u]});
            f[u][i][1] = min({f[u][i][1], min(f[bigChild][i - 1][1], f[bigChild][i - 1][0]) + d[u]});
        }
    }   
    int cnt = 1 + child[bigChild];
    for (int v : a[u])
        if (v != bigChild) {
            dfs(v);
            cnt += child[v];
            for (int i = 1; i <= cnt; i++) {
                tmp[i][0] = tmp[i][1] = INF;
                for (int j = 1; j <= min(i, child[v]); j++) {
                    tmp[i][0] = min(tmp[i][0], f[v][j][0] + f[u][i - j][0]);
                    if (i - j > 0)
                        tmp[i][1] = min(tmp[i][1], min(f[v][j][0], f[v][j][1]) + f[u][i - j][1]);
                }
            }
            for (int i = 1; i <= cnt; i++) {
                f[u][i][0] = min(f[u][i][0], tmp[i][0]);
                f[u][i][1] = min(f[u][i][1], tmp[i][1]);
            }
        }
}

void prepare(int u) {
    child[u] = 1;
    for (int v : a[u]) {
        prepare(v);
        child[u] += child[v];
    }
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    #ifndef ONLINE_JUDGE
        freopen("nhap.inp", "r", stdin);
        freopen("nhap.out", "w", stdout);
    #endif

    int _t = 1;
    while (_t--) {
        cin >> n >> W;
        for (int i = 1; i <= n; i++) {
            cin >> c[i] >> d[i];
            d[i] = c[i] - d[i];
            if (i > 1) {
                int u; cin >> u;
                a[u].push_back(i);
            }
        }
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= n; j++)
                f[i][j][0] = f[i][j][1] = INF;
        prepare(1);
        dfs(1);
        for (int i = 1; i <= n; i++)
            if (f[1][i][0] <= W || f[1][i][1] <= W)
                res = i;
        cout << res;
    }
    return 0;   
}