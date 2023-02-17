// https://cses.fi/problemset/task/2431
#include <bits/stdc++.h>
using namespace std;

#define Fname ((string) "test")
#define int long long
#define ii pair <int, int>
#define iii pair <int, ii>
#define fi first
#define se second
#define endl '\n'

int cnt(int n) {
	int p = 1, d = 1;
	unsigned int res = 0;
	for (; p * 10 - 1 <= n; p *= 10, d++)
		res += 9 * p * d;
	return res + d * (n - p + 1);
}

int cnp(int l, int r, int k) {
    if (l == r)
 		return l;
	int m = (l + r) / 2;   
	if (cnt(m) >= k)
		return cnp(l, m, k);
	return cnp(m + 1, r, k);
}

int Pow(int n, int k) {
	if (k < 2) 
		return (k ? n : 1);
	int tmp = Pow(n, k / 2);
	tmp *= tmp;
	return (k % 2 ? tmp * n : tmp);
}

int ans(int k) {
    int n = cnp(1, 1e18, k);
	k -= cnt(n - 1);
	int tmp = n, len = 0;
	while (tmp) {
		tmp /= 10;
		len++;
	}
	return n / Pow(10, len - k) % 10;
}

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
		int n;
        cin >> n;
        cout << ans(n) << endl;
	}
	
	return 0;
}