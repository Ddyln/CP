#include <bits/stdc++.h>
using namespace std;

#define Fname ((string) "test")
#define int long long
#define ii pair <int, int>
#define iii pair <int, ii>
#define fi first
#define se second
#define endl '\n'
const int N = (1 << 16) + 5;

int n, k, ans[N], c[N];

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
		memset(c, 0, sizeof(c));
		cin >> n >> k;
		if (n < 5 && k == n - 1)		
			cout << "-1\n";
		else {
			for (int i = 0; i < n / 2; i++)
				ans[i] = n - i - 1, ans[n - i - 1] = i;
			if (k == n - 1) {
				ans[1] = n - 3;
				ans[n - 3] = 1;
				ans[n - 2] = n - 1;
				ans[n - 1] = n - 2;
				ans[0] = 2;
				ans[2] = 0;
			} else {
				ans[0] = n - k - 1;
				ans[n - k - 1] = 0;
				ans[k] = n - 1;
				ans[n - 1] = k;
			}
			for (int i = 0; i < n; i++)
				if (!c[i]) {
					cout << i << ' ' << ans[i] << endl;
					c[i] = c[ans[i]] = 1;
				}
		}
		cout << endl;
	}

	return 0;
}