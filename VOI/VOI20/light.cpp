#include <bits/stdc++.h>
using namespace std;

#define Fname ((string) "test")
#define int long long
#define ii pair <int, int>
#define iii pair <int, ii>
#define fi first
#define se second
#define endl '\n'
struct RECT {
	int x1, y1, x2, y2;
};

int n, m, k;
vector <vector <int>> a, b;
vector <RECT> v;

bool cmp(const RECT &a, const RECT &b) {
	return (a.x1 * m + a.y1 < b.x1 * m + b.y1);
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
		cin >> n >> m >> k;
		a.resize(n + 1);
		b.resize(n + 1);
		for (int i = 1; i <= n; i++) {
			a[i].resize(m + 1);
			b[i].resize(m + 1);
			for (int j = 1; j <= m; j++) {
				cin >> a[i][j];
				b[i][j] = a[i][j];
			}
		}
		for (int i = 1; i <= k; i++) {
			int x1, y1, x2, y2;
			cin >> x1 >> y1 >> x2 >> y2;
			v.push_back({x1, y1, x2, y2});
		}
		sort(v.begin(), v.end(), cmp);
		int res = 1000000000;
		for (int val = 1; val < 3; val++) {
			int s = 0;
			for (RECT &tmp : v) {
				if (a[tmp.x1][tmp.y1] != val) {
					int cnt = (val - a[tmp.x1][tmp.y1] + 3) % 3;
					s += cnt;
					for (int i = tmp.x1; i <= tmp.x2; i++)
						for (int j = tmp.y1; j <= tmp.y2; j++)
							(a[i][j] += cnt) %= 3;
				}
			}
			bool ok = 1;
			for (int i = 1; i <= n; i++)
				for (int j = 1; j <= m; j++) {
					if (a[i][j] != val)
						ok = 0;
					a[i][j] = b[i][j];
				}
			if (ok) 
				res = min(res, s);
		}
		cout << (res == 1000000000 ? -1 : res);
	}

	return 0;
}