#include <bits/stdc++.h>
using namespace std;

#define Fname ((string) "test")
#define int long long
#define ii pair <int, int>
#define iii pair <int, ii>
#define fi first
#define se second
#define endl '\n'

const int N = 9e4 + 4;

int n, q, a[N], sum[N], budget, len;

int cnp(int l, int r) {
	if (l == r)
		return l;
	int m = (l + r + 1) / 2;
	if (m + len > n)
		return cnp(l, m - 1);
	return (sum[m + len - 1] - sum[m - 1] <= budget ? cnp(m, r) : cnp(l, m - 1));
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
		cin >> n >> q;
		for (int i = 1; i <= n; i++) 
			cin >> a[i];
		sort(a + 1, a + 1 + n);
		for (int i = 1; i <= n; i++) 
			sum[i] = sum[i - 1] + a[i];
		while (q--) {
			cin >> budget;
			len = upper_bound(sum + 1, sum + 1 + n, budget) - sum - 1;
			cout << len << ' ' << a[cnp(1, n - len + 1)] << endl;
		}
	}
	
	return 0;
}