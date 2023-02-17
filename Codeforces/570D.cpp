#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
const int N = 5e5 + 5;
typedef pair <int, int> ii;

int n, m, child[N], dep[N], cnt[N][26], ans[N], key[N];
vector <int> a[N], allChild[N];
vector <ii> query[N];

void prepare(int u) {
    child[u] = 1;
    for (int v : a[u]) {
        dep[v] = dep[u] + 1;
        prepare(v);
        child[u] += child[v];
    }
}

bool check(int h) {
    int res = 0;
    for (int i = 0; i < 26; i++)
        res += cnt[h][i] % 2;
    return (res < 2);
}

void dfs(int u, bool keep) {
    int bigChild = 0;
    for (int &v : a[u])
        if (child[v] > child[bigChild])
            bigChild = v;
    
    for (int &v : a[u])
        if (v != bigChild)
            dfs(v, 0);
    
    if (bigChild) {
        dfs(bigChild, 1);
        swap(allChild[bigChild], allChild[u]);
    }
    allChild[u].push_back(u);
    cnt[dep[u]][key[u]]++;

    for (int &v : a[u])
        if (v != bigChild)
            for (int &x : allChild[v]) {
                allChild[u].push_back(x);
                cnt[dep[x]][key[x]]++;
            }
    
    for (ii &q: query[u]) {
        int id = q.first, h = q.second;
        ans[id] = check(h);
    }

    if (!keep)
        for (int &v : allChild[u])
            cnt[dep[v]][key[v]]--;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    #ifndef ONLINE_JUDGE   
        freopen("nhap.inp", "r", stdin);
        freopen("nhap.out", "w", stdout);
    #endif

    cin >> n >> m;
    for (int i = 2; i <= n; i++) {
        int p; cin >> p;
        a[p].push_back(i);
    }
    for (int i = 1; i <= n; i++) {
        char c; cin >> c;
        key[i] = c - 'a';
    }
    for (int i = 1; i <= m; i++) {
        int u, h; cin >> u >> h;
        query[u].push_back({m - i, h});
    }
    dep[1] = 1;
    prepare(1);
    dfs(1, 1);
    while (m--) cout << (ans[m] ? "Yes\n" : "No\n");
    return 0;
}