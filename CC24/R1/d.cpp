#include <bits/stdc++.h>
using namespace std;

#define Fname ((string) "test")
#define int long long
#define ii pair <int, int>
#define iii pair <int, ii>
#define fi first
#define se second
#define endl '\n'
const int N = 102;
const int INF = 1e9;

int n, a[N], f[N][N], sum[N], L, R;

int get(int l, int r) {
    return sum[r] - sum[l - 1];
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
        cin >> n >> L >> R;
        for (int i = 1; i <= n; i++) {
            cin >> a[i];
            sum[i] = sum[i - 1] + a[i];
        }
        for (int i = 1; i <= n; i++)
            for (int j = 0; j <= n; j++)
                f[i][j] = INF;
        f[1][1] = f[0][0] = 0;
        for (int i = 2; i <= n; i++) {
            f[i][i] = 0;
            for (int j = i - 1; j >= 1; j--) {
                f[i][j] = f[i - 1][j - 1];
                for (int k = L; k <= R && i - k >= 0; k++)
                    f[i][j] = min(f[i - k][j - 1] + get(i - k + 1, i), f[i][j]);
            }
        }
        cerr << f[3][2];
        cout << f[n][1];
	}
	
	return 0;
}