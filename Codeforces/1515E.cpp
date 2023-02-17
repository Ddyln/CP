#include <bits/stdc++.h>
using namespace std;

#define Fname ((string) "test")
#define int long long
#define ii pair <int, int>
#define iii pair <int, ii>
#define fi first
#define se second
#define endl '\n'
const int N = 405;

int n, M, C[N][N], f[N][N], res;

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
        cin >> n >> M;
        C[0][0] = 1;
        for (int p2 = 1, i = 1; i <= n; p2 = p2 * 2 % M, i++) {
        	f[i][i] = p2;
        	C[i][0] = 1;
        	for (int j = 1; j <= i; j++)	
        		C[i][j] = (C[i - 1][j] + C[i - 1][j - 1]) % M;
        }

        res = f[n][n];
        for (int i = 1; i <= n; i++)
        	for (int j = 1; j < i; j++) {
        		for (int k = 2; k < i; k++)
        			if (j - i + k > 0)
        				(f[i][j] += (f[k - 1][j - i + k] * C[j][i - k]) % M * f[i - k][i - k]) %= M;
        		if (i == n)
        			(res += f[i][j]) %= M;
        	}
        cout << res;
	}

	return 0;
}
