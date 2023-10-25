#include <bits/stdc++.h>
using namespace std;

#define Fname ((string) "bridge")
#define ll long long
#define ii pair <ll, ll>
#define fi first
#define se second
#define endl '\n'

const int N = 1e5 + 3;

int n, m, q, par[N][20], cnt[N][20], num[N], low[N], h[N], Time = 0;
vector <int> a[N];
bool vis[N];

void dfs(int u) {
    num[u] = low[u] = ++Time;
    for (int i = 1; i <= 17; i++)
        par[u][i] = par[par[u][i - 1]][i - 1];
    for (int v : a[u]) 
        if (v == par[u][0])
            continue;
        else if (!num[v]) {
            par[v][0] = u;
            h[v] = h[u] + 1;
            dfs(v);
            low[u] = min(low[u], low[v]);
            if (low[v] > num[u]) {
                cnt[v][0] = 1;
            }
        }
        else    
            low[u] = min(low[u], num[v]);
}  

void buildTable(int u) {
    vis[u] = 1;
    for (int i = 1; i <= 17; i++)
        cnt[u][i] = cnt[u][i - 1] + cnt[par[u][i - 1]][i - 1];
    for (int v : a[u])
        if (!vis[v]) 
            buildTable(v);
}

int lca(int u, int v) {
    if (h[u] < h[v])
        swap(u, v);
    for (int i = 17; i >= 0; i--)
        if (h[par[u][i]] >= h[v])
            u = par[u][i];
    if (u == v)
        return u;
    for (int i = 17; i >= 0; i--)
        if (par[u][i] != par[v][i])
            u = par[u][i], v = par[v][i];
    return par[u][0];
}

int calc(int u, int v) {
    int k = lca(u, v), res = 0;
    for (int i = 17; i >= 0; i--) {
        if (h[par[u][i]] >= h[k]) {
            res += cnt[u][i];
            u = par[u][i];
        }
        if (h[par[v][i]] >= h[k]) {
            res += cnt[v][i];
            v = par[v][i];
        }
    }
    return res;
}

bool isAncestor(int u, int v) {
    for (int i = 17; i >= 0; i--)
        if (h[par[v][i]] >= h[u])
            v = par[v][i];
    return (v == u);
}

bool related(int A, int B) {
    if (h[A] > h[B])
        swap(A, B);
    return isAncestor(A, B);
}

int intersect(int A, int B, int u, int v) {
    if (h[A] > h[B])
        swap(A, B);
    if (h[u] > h[v])
        swap(u, v);
    if (!related(A, u))
        return 0;
    if (!related(v, B)) {
        for (int i = 17; i >= 0; i--)   
            if (!related(par[v][i], B))
                v = par[v][i];
        v = par[v][0];
    }
    if (!isAncestor(B, u) && !isAncestor(v, A)) 
        return calc((h[A] > h[u] ? A : u), (h[B] > h[v] ? v : B));
    return 0;
}

int query(int A, int B, int u, int v) {
    int k = lca(u, v), res = calc(u, v);
    if (related(A, B)) 
        res -= intersect(A, B, k, u) + intersect(A, B, k, v);
    else {
        int k2 = lca(A, B);
        res -= intersect(A, k2, k, u) + intersect(A, k2, k, v);
        res -= intersect(B, k2, k, u) + intersect(B, k2, k, v);
    }
    return res;
}

signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
    #ifdef lan_ngu
        freopen("test.inp", "r", stdin);
        freopen("test.out", "w", stdout);
    #else
        freopen((Fname + ".inp").c_str(), "r", stdin);
        freopen((Fname + ".out").c_str(), "w", stdout);
    #endif
	// int _nt; cin >> _nt;
	int _nt = 1;
	while (_nt--) {
        cin >> n >> m >> q;
        for (int i = 1; i <= m; i++) {
            int u, v; cin >> u >> v;
            a[u].push_back(v);
            a[v].push_back(u);
        }
        h[0] = -1;
        dfs(1);
        buildTable(1);
        while (q--) {
            int A, B, C, D; 
            cin >> A >> B >> C >> D;
            cout << query(A, B, C, D) << endl;
        }
	}
	
	return 0;
}
