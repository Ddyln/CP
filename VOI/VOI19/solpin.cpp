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

int n, m, a[N][N], f[N][N], q, x, y;

int get(int x1, int y1, int x2, int y2) {
	return f[x2][y2] - f[x2][y1 - 1] - f[x1 - 1][y2] + f[x1 - 1][y1 - 1];
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
		cin >> n >> m;
		for (int i = 1; i <= n; i++) 
			for (int j = 1; j <= m; j++) {
				cin >> a[i][j];
				f[i][j] = f[i - 1][j] + f[i][j - 1] - f[i - 1][j - 1] + a[i][j];
			}
		cin >> q;
		x = y = 0;
		while (q--) {
			int t; cin >> t;
			if (t == 0) {
				int tmp; cin >> tmp;
				x = (x + tmp) % m;
				cin >> tmp;
				y = (y + tmp) % n;
			} else {
				int x1, y1, x2, y2, res = 0; cin >> x1 >> y1 >> x2 >> y2;
				if (x2 <= n - y) {
					if (y2 <= m - x)
						res += get(x1 + y, y1 + x, x2 + y, y2 + x);
					else if (y1 <= m - x) {
						res += get(x1 + y, y1 + x, x2 + y, m);
						res += get(x1 + y, 1, x2 + y, y2 - (m - x));
					} else {
						res += get(x1 + y, y1 - (m - x), x2 + y, y2 - (m - x));
					}
				} else if (x1 > n - y) {
					if (y2 <= m - x)
						res += get(x1 - (n - y), y1 + x, x2 - (n - y), y2 + x);
					else if (y1 <= m - x) {
						res += get(x1 - (n - y), y1 + x, x2 - (n - y), m);
						res += get(x1 - (n - y), 1, x2 - (n - y), y2 - (m - x));
					} else {
						res += get(x1 - (n - y), y1 - (m - x), x2 - (n - y), y2 - (m - x));
					}
				} else if (y2 <= m - x) {
					res += get(x1 + y, y1 + x, n, y2 + x);
					res += get(1, y1 + x, x2 - (n - y), y2 + x);
				} else if (y1 > m - x) {
					res += get(x1 + y, y1 - (m - x), n, y2 - (m - x));
					res += get(1, y1 - (m - x), x2 - (n - y), y2 - (m - x));
				} else {
					res += get(x1 + y, y1 + x, n, m);
					res += get(1, y1 + x, x2 - (n - y), m);
					res += get(x1 + y, 1, n, y2 - (m - x));
					res += get(1, 1, x2 - (n - y), y2 - (m - x));
				}
				cout << res << endl;
			}
		}	
	}

	return 0;
}