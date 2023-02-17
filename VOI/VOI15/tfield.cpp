#include <bits/stdc++.h>
using namespace std;

#define Fname ((string) "test")
#define int long long
#define ii pair <int, int>
#define iii pair <int, ii>
#define fi first
#define se second
#define endl '\n'
const int N = 1005;

int m, k, x[N], y[N], f[N], cnt[N], res;
ii a[N];
vector <ii> v;

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
		cin >> m >> k;
		for (int i = 1; i <= m; i++) {
			int n; cin >> n >> a[i].se;
			for (int j = 1; j <= n; j++)
				cin >> x[j] >> y[j];
			x[n + 1] = x[1], y[n + 1] = y[1];
			for (int j = 1; j <= n; j++)
				a[i].fi += x[j] * y[j + 1] - x[j + 1] * y[j];
			a[i].fi = abs(a[i].fi);
		}
		sort(a + 1, a + 1 + m);
		for (int i = 1; i <= m; i++) 
			f[i] = a[i].fi - a[i - 1].fi;

		for (int i = 1; i <= m; i++) {
			int Max = 0, s = 0;
			for (int j = 1; j <= m; j++)
				cnt[j] = 0;
			for (int j = i; j <= m; j++) {
				cnt[a[j].se]++;
				s += f[j];
				Max = max(Max, cnt[a[j].se]);
				if (j - i + 1 - Max <= k)
					res = max(res, s);
			}
		}
		cout << res / 2;
		if (res % 2 == 0)
			cout << ".0";
		else
			cout << ".5";
	}

	return 0;
}
