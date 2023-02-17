#include <bits/stdc++.h>
using namespace std;

#define Fname ((string) "test")
#define int long long
#define ii pair <int, int>
#define iii pair <int, ii>
#define fi first
#define se second
#define endl '\n'
const int N = 2005;
const int M = 1e9 + 7;

int n, m, ft[N];
bool slot[N], have[N];

int Pow(int n, int k) {
	if (k < 2)
		return (k == 1 ? n : 1);
	int tmp = Pow(n, k / 2);
	tmp = tmp * tmp % M;
	return (k & 1 ? tmp * n % M : tmp);
}

int C(int n, int k) {
	if (k == 0)
		return 1;
	int res = ft[n];
	res = res * Pow(ft[k], M - 2) % M;
	res = res * Pow(ft[n - k], M - 2) % M;
	return res;
}

signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	#ifdef lan_ngu
		freopen((Fname + ".inp").c_str(), "r", stdin);
		freopen((Fname + ".out").c_str(), "w", stdout);
	#endif

	ft[0] = 1;
	for (int i = 1; i <= 2000; i++)
		ft[i] = ft[i - 1] * i % M;

	// int _nt; cin >> _nt;
	int _nt = 1;
	while (_nt--) {
		cin >> n;
		for (int i = 1; i <= n; i++) {
			int a; cin >> a;
			if (a < 0) {
				m++;
				slot[i] = 1;
			}
			else
				have[a] = 1;
		}
		int x = 0, res = 0;
		for (int i = 1; i <= n; i++)
			if (slot[i] && !have[i])
				x++;
		for (int i = 0; i <= x; i++)
			if (i % 2 == 1)
				res = (res - C(x, i) * ft[m - i] % M + M) % M;
			else
				res = (res + C(x, i) * ft[m - i] % M) % M;
		cout << res;
	}

	return 0;
}