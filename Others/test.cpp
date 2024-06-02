#include <bits/stdc++.h>
using namespace std;

const int N = 10000;
int n, m, col[N];
vector <int> a[N];
map <string, int> mp;

bool check(int u) {
    for (int v : a[u])
        if (col[v] == -1) continue;
        else if (col[v] == col[u])
            return 0;
    return 1;
}

void Try(int u, int k) {
    if (u > n) {
        for (int i = 1; i <= n; i++)
            cout << col[i] << ' ';
        exit(0);
    }
    for (int c = 0; c < k; c++) {
        col[u] = c;
        if (!check(u)) continue;
        Try(u + 1, k);
    }
    col[u] = -1;
}

void TryColoring(int numOfColor) {
    memset(col, -1, sizeof col);
    Try(1, numOfColor);
}

signed main() {
    #ifdef lan_ngu
        freopen("test.inp", "r", stdin);
    #endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        string s;
        cin >> s;
        mp[s] = i;
    }
    for (int i = 1; i <= m; i++) {
        string u, v;
        cin >> u >> v;
        a[mp[u]].push_back(mp[v]);
        a[mp[v]].push_back(mp[u]);
    }
    for (int i = 1; i <= n; i++)
        TryColoring(i);
    return 0;
}