#include <bits/stdc++.h>
using namespace std;

#define Fname ((string) "test")
#define ii pair <int, int>
#define iii pair <int, ii>
#define fi first
#define se second
#define endl '\n'
const int N = 505;
const int MOD = 1e9 + 7;

int n, m, p, f[N][N][3], sum[2][N][N][3];

signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	#ifdef lan_ngu
        freopen("test.inp", "r", stdin);
        freopen("test.out", "w", stdout);
    #endif

	// int _nt; cin >> _nt;
	int _nt = 1;
	while (_nt--) {
        cin >> n >> m >> p;
        for (int i = 1; i <= m; i++)
            sum[1][0][i][2] = i;
        for (int i = 2; i <= n; i++) {
            int cur = i & 1, prv = cur ^ 1;
            memset(f, 0, sizeof f);
            memset(sum[cur], 0, sizeof sum[cur]);
            for (int k = 0; k <= p; k++)
                for (int j = 1; j <= m; j++) {
                    for (int status = 0; status < 3; status++)
                        sum[cur][k][j][status] = sum[cur][k][j - 1][status];
                    for (int status = 0; status < 3; status++)
                        (f[k][j][0] += (sum[prv][k][j][status] - sum[prv][k][j - 1][status] + MOD) % MOD) %= MOD;
                    for (int status = 0; status < 3; status++)
                        (f[k][j][1] += sum[prv][k][j - 1][status]) %= MOD;
                    if (k)
                        (f[k][j][2] += (sum[prv][k - 1][m][1] - sum[prv][k - 1][j][1] + MOD) % MOD) %= MOD;
                    (f[k][j][2] += (sum[prv][k][m][0] - sum[prv][k][j][0] + MOD) % MOD) %= MOD;
                    (f[k][j][2] += (sum[prv][k][m][2] - sum[prv][k][j][2] + MOD) % MOD) %= MOD;
                    
                    for (int status = 0; status < 3; status++)
                        (sum[cur][k][j][status] += f[k][j][status]) %= MOD;
                }
        }
        int res = 0;
        for (int status = 0; status < 3; status++)
            (res += sum[n & 1][p][m][status]) %= MOD;
        cout << res;
    }	
	return 0;
}