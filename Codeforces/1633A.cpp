#include <bits/stdc++.h>
using namespace std;

#define Fname ((string) "test")
#define int long long
#define ii pair <int, int>
#define iii pair <int, ii>
#define fi first
#define se second
#define endl '\n'

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
		int n, l, r; cin >> n;	
		if (n < 100)
			l = 10, r = 99;
		else if (n < 10)
			l = 0, r = 9;
		else
			l = 100, r = 999;
		int res = 5, res2;
		for (int i = l; i <= r; i++) {
			if (i % 7 == 0) {
				int tmp = n, tmp2 = i, s = 0;
				while (tmp) {
					s += (tmp % 10 != tmp2 % 10);
					tmp /= 10;
					tmp2 /= 10;
				}
				if (s < res)
					res = s, res2 = i;
			}
		}
		cout << res2 << endl;
	}

	return 0;
}