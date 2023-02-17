#include <bits/stdc++.h>
using namespace std;

#define Fname ((string) "test")
#define int long long
#define ii pair <int, int>
#define iii pair <int, ii>
#define fi first
#define se secondi
#define endl '\n'
const int M = 998244353;
const int N = 2e5 + 5;

int n, k, a[N], res, f[N][5];

int cal(int j, int i) {
	int res = 1, tmp = j;
	for (; i <= n + 2; i += 2) {
		if (a[i] == -1)
			continue;
		if (i > 1 && a[i - 2] == a[i]) 
			res = 0;
		int len = (i - j) / 2 - 1;
		if (len) {
			if (j != tmp) {
				if (i <= n) {
					if (a[i] != a[j]) 
						res = res * f[len][3] % M;
					else 
						res = res * f[len][2] % M;
				} else
					res = res * f[len][0] % M;
			} else {
				if (i <= n)
					res = res * f[len][0] % M;
				else
					res = res * ((f[len][0] + f[len][1]) % M) % M;
			}
		}
		j = i;
	}
	return res;
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
		cin >> n >> k;
		for (int i = 1; i <= n; i++)
			cin >> a[i];	
		f[1][0] = f[1][2] = k - 1;
		f[0][0] = f[1][1] = f[1][4] = 1;
		f[1][3] = k - 2;
		// 0: 1 border
		// 1: 1 border and the last element equals the border
		// 2: 2 equal borders
		// 3: 2 different borders
		// 4: 2 different borders and the one next to the 1st border equals the 1st border
		for (int i = 2; i <= n; i++) {
			f[i][0] = (f[i - 1][1] * (k - 1) % M + f[i - 1][0] * (k - 2) % M) % M;
			f[i][1] = f[i - 1][0];
			f[i][2] = (f[i - 1][2] * (k - 2) % M + (f[i - 2][2] * (k - 1) % M)) % M;
			f[i][3] = (f[i - 1][3] * (k - 2) % M + f[i - 1][4] * (k - 1) % M) % M;
			f[i][4] = f[i - 1][3];
		}
		cout << cal(-1, 1) * cal(0, 2) % M;
	}

	return 0;
}