#include <bits/stdc++.h>
using namespace std;

#define Fname ((string) "test")
#define int long long
#define ii pair <int, int>
#define iii pair <int, ii>
#define fi first
#define se second
#define endl '\n'

int Try(int a, int b, int n) {
    if (a < b)
        return 0;
    if (n == 2)
        return 1;
    return Try(b, a - b, n - 1);
}

int solve(int n, int k) {
    if (k > 29)
        return 0;
    if (k == 1)
        return 1;
    int res = 0;
    for (int i = n; i >= 0; i--)
        res += Try(n, i, k);
    return res;
}

signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	#ifdef lan_ngu
		freopen((Fname + ".inp").c_str(), "r", stdin);
		freopen((Fname + ".out").c_str(), "w", stdout);
	#endif

	int _nt, n, k; cin >> _nt;
	// int _nt = 1;
	while (_nt--) {
        cin >> n >> k;
        cout << solve(n, k) << endl;
	}
	
	return 0;
}