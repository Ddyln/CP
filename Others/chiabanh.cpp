#include <bits/stdc++.h>
using namespace std;

#define Fname ((string) "test")
#define int long long
#define ii pair <int, int>
#define iii pair <int, ii>
#define fi first
#define se second
#define endl '\n'

const int N = 5e5 + 5;

int n, a[N], sum[N];
map <int, int> suf;

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
			sum[i] = sum[i - 1] + a[i];
		}
		if (sum[n] % 3 != 0) 
			 return cout << 0, 0;
		for (int i = n; i > 1; i--) {
			suf[sum[n] - sum[i - 1]]++;
		}
		int res = 0;
		for (int i = 1; i < n - 1; i++) {
			suf[sum[n] - sum[i]]--;
			if (sum[i] == sum[n] / 3) 
				res += suf[sum[i]];
		}
		cout << res;
	}
	
	return 0;
}