#include <bits/stdc++.h>
using namespace std;

#define Fname ((string) "sc6")
#define int long long
#define ii pair <int, int>
#define iii pair <int, ii>
#define fi first
#define se second
#define endl '\n'
const int N = 1e4 + 5;

int n, k, pre[N];

signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	freopen((Fname + ".inp").c_str(), "r", stdin);
	freopen((Fname + ".out").c_str(), "w", stdout);

	int _nt; cin >> _nt;
	// int _nt = 1;
	while (_nt--) {
		cin >> n >> k;
		for (int i = 1; i <= n; i++) {
			int a; cin >> a;
			pre[i] = pre[i - 1] + a;
		}
		if (k == 2) {
			int res = 0;
			for (int i = 1; i < n; i++)
				res = max(res, abs(pre[n] - 2 * pre[i]));
			cout << res << endl;
		} else
			cout << "._.\n";
	}

	return 0;
}