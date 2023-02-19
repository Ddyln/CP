#include <bits/stdc++.h>
using namespace std;

#define Fname ((string) "test")
#define int long long
#define ii pair <int, int>
#define iii pair <int, ii>
#define fi first
#define se second
#define endl '\n'

const int M = 998244353;
const int N = 300;

int n, a[N + 2], f[N + 3][N * N + 3][2], res = 0;

int Sign(int s) {
    return (s ? -1 : 1);
}

int GetSign(int a) {
    return (a >= 0 ? 0 : 1);
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
        for (int i = 1; i <= n; i++)
            cin >> a[i];
        f[2][a[2]][0] = 1;
        for (int i = 2; i < n; i++)
            for (int j = 0; j <= 9e4; j++)
                for (int s = 0; s < 2; s++) 
                    if (f[i][j][s]) {
                        (f[i + 1][abs(a[i + 1] + j * Sign(s))][GetSign(a[i + 1] + j * Sign(s))] += f[i][j][s]) %= M;
                        if (j != 0)
                            (f[i + 1][abs(a[i + 1] - j * Sign(s))][GetSign(a[i + 1] - j * Sign(s))] += f[i][j][s]) %= M;
                    }
        for (int j = 0; j <= 9e4; j++)
            for (int s = 0; s < 2; s++)
                (res += f[n][j][s]) %= M;
        cout << res;
	}
	
	return 0;
}