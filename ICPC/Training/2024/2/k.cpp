#include <bits/stdc++.h>
using namespace std;

#define Fname ((string) "test")
#define int long long
#define ii pair <int, int>
#define iii pair <int, ii>
#define fi first
#define se second
#define endl '\n'
const int N = 2e5 + 5;
const int MOD = 1e9 + 7;

int n, f[N], ans[N];
vector <int> a[N];

int Pow(int n, int k) {
    if (k == 1) return n;
    if (k == 0) return 1;
    int ans = Pow(n, k / 2);
    ans = ans * ans % MOD;
    return (k & 1 ? ans * n % MOD : ans);
}

int inv(int n) {
    return Pow(n % MOD, MOD - 2);
}

void init(int u, int par) {
    f[u] = 1;
    for (int v : a[u]) {
        if (v == par) continue;
        init(v, u);
        (f[u] *= (f[v] + 1) % MOD) %= MOD;
    }
}

void dfs(int u, int par) {
    if (u == par)
        ans[u] = f[u];
    else
        ans[u] = (f[u] * ((ans[par] * inv(f[u] + 1) % MOD + 1) % MOD)) % MOD;
    for (int v : a[u]) {
        if (v == par) continue;
        dfs(v, u);
    }
}

signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	#ifdef lan_ngu
        freopen((Fname + ".inp").c_str(), "r", stdin);
        freopen((Fname + ".out").c_str(), "w", stdout);
    #endif

	// int _nt; cin >> _nt;
	int _nt = 1;
	while (_nt--) {
        cin >> n;
        for (int u = 2; u <= n; u++) {
            int v; cin >> v;
            a[u].push_back(v);
            a[v].push_back(u);
        }
        init(1, 1);
        dfs(1, 1);
        for (int i = 1; i <= n; i++)
            cout << ans[i] << ' ';
	}
	
	return 0;
}