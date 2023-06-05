#include <bits/stdc++.h>
using namespace std;

#define Fname ((string) "test")
#define int long long
#define ii pair <int, int>
#define iii pair <int, ii>
#define fi first
#define se second
#define endl '\n'

const int N = 505;
char a[N][N];
int n, m, ok = 0;

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
		// Code here
        cin >> m >> n;
        for (int i = 1; i <= m; i++)
            for (int j = 1; j <= n; j++) {
                cin >> a[i][j];
                if (i > 1 && j > 1) {
                    if (a[i][j] == a[i - 1][j] && a[i - 1][j - 1] != a[i][j - 1] && a[i][j] != a[i][j - 1] && a[i][j] != a[i - 1][j - 1])
                        ok = 1;
                }
            }
        cout << (ok ? "YES" : "NO");
	}
	
	return 0;
}