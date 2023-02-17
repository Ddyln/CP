#include <bits/stdc++.h>
using namespace std;

#define Fname ((string) "test")
#define int long long
#define ii pair <int, int>
#define iii pair <int, ii>
#define fi first
#define se second
#define endl '\n'

const int N = 2e5 + 5;
const int A = 1e6 + 5;

int n, a[N], res, pos[A];

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
		sort(a + 1, a + 1 + n);
		n = unique(a + 1, a + 1 + n) - a - 1;
		for (int i = 1; i <= n; i++)
			pos[a[i]] = i;
		for (int i = 1; i <= n; i++) {
			for (int j = a[i] * 2; j <= 1e6; j += a[i])
				if (pos[j] > i + 1)
					res = max(res, a[pos[j] - 1] % a[i]);
			res = max(res, a[n] % a[i]);
		}
		cout << res;
	}
	
	return 0;
}