#include <bits/stdc++.h>
using namespace std;

#define Fname ((string) "lcs")
#define ll long long
#define ii pair <ll, ll>
#define fi first
#define se second
#define endl '\n'

const int N = 2e4 + 4;
const int MOD = 123456789;

int n, m, a[N], b[N];
ii f[2][N];
vector <int> v, pos[2 * N];
set <int> s;

ostream& operator << (ostream& outDev, ii a) {
    outDev << a.fi << ' ' << a.se;
    return outDev;
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
        cin >> n >> m;
        for (int i = 1; i <= n; i++) 
            cin >> a[i];
        for (int i = 1; i <= m; i++) 
            cin >> b[i];

        for (int i = 0; i < 2; i++)
            f[i][0] = {0, 1};
        for (int i = 0; i <= m; i++)
            f[0][i] = {0, 1};

        for (int i = 1; i <= n; i++) {
            int cur = i & 1, prv = cur ^ 1;
            for (int j = 1; j <= m; j++) {
                if (f[prv][j].fi > f[cur][j - 1].fi)
                    f[cur][j] = f[prv][j];
                else {
                    f[cur][j] = f[cur][j - 1];
                    if (f[prv][j].fi == f[cur][j - 1].fi) {
                        f[cur][j].se = (f[prv][j].se + f[cur][j - 1].se) % MOD;
                        if (f[prv][j - 1].fi == f[cur][j].fi)
                            (f[cur][j].se -= f[prv][j - 1].se - MOD) %= MOD;
                    }
                }
                if (a[i] == b[j])
                    f[cur][j] = {f[prv][j - 1].fi + 1, f[prv][j - 1].se};
            }
        }
        cout << f[n & 1][m];
	}
	
	return 0;
}
