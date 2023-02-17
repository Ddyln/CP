#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
typedef pair <int, int> ii;
const int N = 1e5 + 5;

int n, m, child[N], dep[N], total, key[N], ans[N];
vector <int> a[N], allChild[N], root;
vector <ii> query[N];
string name[N];
set <int> cur;
set <string> s[N];

void prepare(int u) {
    child[u] = 1;
    for (int &v : a[u]) {
        dep[v] = dep[u] + 1;
        prepare(v);
        child[u] += child[v];
    }
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
    s[dep[u]].insert(name[u]);
    cur.insert(dep[u]);

    for (int &v : a[u])
        if (v != bigChild)
            for (int &x : allChild[v]) {
                allChild[u].push_back(x);
                s[dep[x]].insert(name[x]);
                cur.insert(dep[x]);
            }

    for (ii &q : query[u]) {
        int id = q.first, h = q.second;
        if (dep[u] + h <= n) 
            ans[id] = s[dep[u] + h].size();
    }

    if (!keep) {
        for (int i : cur)
            s[i].clear();
        cur.clear();
    }
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    #ifndef ONLINE_JUDGE 
        freopen("nhap.inp", "r", stdin);
        freopen("nhap.out", "w", stdout);
    #endif

    cin >> n;
    for (int i = 1; i <= n; i++) {
        int tmp; cin >> name[i] >> tmp;
        if (!tmp)
            root.push_back(i);
        else
            a[tmp].push_back(i);
    }
    cin >> m;
    for (int i = 1; i <= m; i++) {
        int u, k; cin >> u >> k;
        query[u].push_back({m - i, k});
    }
    for (int &u : root) {
        prepare(u);
        dfs(u, 0);
    }

    while (m--) cout << ans[m] << endl;
    return 0;
}