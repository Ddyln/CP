#include <bits/stdc++.h>
using namespace std;

#define Fname ((string) "lcs")
#define ll long long
#define ii pair <ll, ll>
#define fi first
#define se second
#define endl '\n'

const int N = 1e4 + 4;
const int MOD = 123456789;

int n, m, a[N], b[N];
ii f[N][N];
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
        for (int i = 1; i <= n; i++) {
            cin >> a[i];
            v.push_back(a[i]);
        }
        for (int i = 1; i <= m; i++) {
            cin >> b[i];
            v.push_back(b[i]);
        }
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= m; j++) {
                if (f[i - 1][j].fi > f[i][j - 1].fi)
                    f[i][j] = f[i - 1][j];
                else {
                    f[i][j] = f[i][j - 1];
                    if (f[i - 1][j].fi == f[i][j - 1].fi)
                        f[i][j].se = max(f[i - 1][j].se, f[i][j - 1].se);
                }
        }
	}
	
	return 0;
}
