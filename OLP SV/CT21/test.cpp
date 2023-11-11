#include <bits/stdc++.h>
using namespace std;

#define Fname ((string) "test")
#define ii pair <int, int>
#define iii pair <int, ii>
#define fi first
#define se second
#define endl '\n'
const int N = 105;
const int MOD = 1e9 + 7;

int n, m, p, f[N][N][N][3];

signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	#ifdef lan_ngu
        freopen("test.inp", "r", stdin);
        freopen("test.ans", "w", stdout);
    #endif

	// int _nt; cin >> _nt;
	int _nt = 1;
	while (_nt--) {
        cin >> n >> m >> p;
        for (int i = 1; i <= m; i++)
            f[1][i][0][2] = 1;
        for (int i = 1; i < n; i++)
            for (int j = 1; j <= m; j++)
                for (int k = 0; k <= p; k++) 
                    for (int status = 0; status < 3; status++)
                        if (f[i][j][k][status]) {
                            for (int nj = 1; nj <= m; nj++) {
                                int nStatus = 0;
                                if (nj > j)
                                    nStatus = 1;
                                else if (nj < j)
                                    nStatus = 2;
                                int nk = k + (status == 1 && nStatus == 2);
                                (f[i + 1][nj][nk][nStatus] += f[i][j][k][status]) %= MOD;
                            }
                        }
        int res = 0;
        for (int i = 1; i <= m; i++)
            for (int j = 0; j < 3; j++)
            (res += f[n][i][p][j]) %= MOD;
        cout << res;
    }	
	return 0;
}
