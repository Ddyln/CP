#include <bits/stdc++.h>
using namespace std;

#define Fname ((string) "test")
#define int long long
#define ii pair <int, int>
#define iii pair <int, ii>
#define fi first
#define se second
#define endl '\n'

int n, pre[2];

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
		pre[0] = pre[1] = 0;
		bool res = 1;
		for (int i = 1; i <= n; i++) {
			int a; cin >> a;
			if (pre[a % 2] > a)
				res = 0;
			pre[a % 2] = a;
		}
		cout << (res ? "Yes\n" : "No\n");
	}

	return 0;
}