#include <bits/stdc++.h>
using namespace std;

#define Fname ((string) "test")
#define int long long
#define ii pair <int, int>
#define iii pair <int, ii>
#define fi first
#define se second
#define endl '\n'
const int INF = 1e16;
const int N = 3005;

int n, a[N], f[N][N];
vector <int> v;

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
		for (int i = 1; i <= n; i++) {
			cin >> a[i];
			a[i] -= i;
			v.push_back(a[i]);
		}
		sort(v.begin(), v.end());
		v.erase(unique(v.begin(), v.end()), v.end());
		int m = v.size();
		for (int i = 1; i <= n; i++) {
			f[i][0] = INF;
			for (int j = 1; j <= m; j++) 
				f[i][j] = min(f[i][j - 1], abs(a[i] - v[j - 1]) + f[i - 1][j]);
		}
		cout << f[n][m];
	}

	return 0;
}