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

int n, a[N], res, b[N];
bool c[N];

signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	#ifdef lan_ngu
		freopen((Fname + ".inp").c_str(), "r", stdin);
		freopen((Fname + ".out").c_str(), "w", stdout);
	#endif

	int _nt; cin >> _nt;
	// int _nt = 1;
	while (_nt--) {
		cin >> n;
		for (int i = 1; i <= n; i++) {
			cin >> a[i];
			b[i] = a[i];
			c[i] = 0;
		}
		res = 0;
		a[0] = a[n + 1] = 1e9;
		for (int i = 1; i <= n; i++)
			if (a[i] > a[i - 1] && a[i] > a[i + 1]) {
				if (c[i - 2]) {
					c[i - 2] = 0;
					a[i - 2] = b[i - 2];
					if (a[i - 2] > a[i])
						a[i - 1] = a[i - 2];					
					else
						a[i - 1] = a[i];
				} else {
					res++;
					if (a[i - 1] > a[i + 1])
						a[i] = a[i - 1];
					else
						a[i] = a[i + 1];
					c[i] = 1;
				}
			}
		cout << res << endl;
		for (int i = 1; i <= n; i++)
			cout << a[i] << ' ';
		cout << endl;
	}

	return 0;
}