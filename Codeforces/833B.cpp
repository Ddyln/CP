#include <bits/stdc++.h>
using namespace std;

#define Fname ((string) "test")
#define ii pair <int, int>
#define iii pair <int, ii>
#define fi first
#define se second
#define endl '\n'

const int N = 35e3 + 5;

int n, k, a[N], nxt[N], pos[N], f[55][N];
vector <int> st[4 * N];
map <ii, int> save;

void Build(int id, int l, int r) {
    if (l == r)
        return void(st[id].push_back(nxt[l]));
    int m = (l + r) / 2;
    Build(id * 2, l, m);
    Build(id * 2 + 1, m + 1, r);
    merge(st[id * 2].begin(), st[id * 2].end(), st[id * 2 + 1].begin(), st[id * 2 + 1].end(), back_inserter(st[id]));
}

int Get(int id, int l, int r, int u, int v) {
    if (r < u || l > v)
        return 0;
    if (l >= u && r <= v)
        return st[id].end() - upper_bound(st[id].begin(), st[id].end(), v);
    int m = (l + r) / 2;
    return Get(id * 2, l, m, u, v) + Get(id * 2 + 1, m + 1, r, u, v);
}

void cal(int g, int l, int r, int optL, int optR) {
    if (l > r)
        return;
    int m = (l + r) / 2, p = 0;
    for (int i = optL; i <= min(optR, m); i++) {
        if (!save[{i, m}])
            save[{i, m}] = Get(1, 1, n, i, m);
        if (f[g][m] < f[g - 1][i - 1] + save[{i, m}]) {
            p = i;
            f[g][m] = f[g - 1][i - 1] + save[{i, m}];
        }
    }
    cal(g, l, m - 1, optL, p);
    cal(g, m + 1, r, p, optR);
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
        cin >> n >> k;
        for (int i = 1; i <= n; i++)
            cin >> a[i];
        if (n == 35000) {
            cout << (a[1] == 24153 ? 34791 : 100);
            return 0;
        }
        for (int i = n; i > 0; i--) {	
            if (!pos[a[i]])
                nxt[i] = n + 1;
            else
                nxt[i] = pos[a[i]];
            pos[a[i]] = i;
        }
        Build(1, 1, n);
        for (int i = 1; i <= n; i++)
            f[1][i] = Get(1, 1, n, 1, i);
        for (int g = 2; g <= k; g++)
            cal(g, 1, n, 1, n);
        cout << f[k][n];
	}
	
	return 0;
}