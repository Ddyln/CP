//http://csloj.ddns.net/problem/627
#include <bits/stdc++.h>
using namespace std;

#define Fname ((string) "test")
#define int long long
#define ii pair <int, int>
#define iii pair <int, ii>
#define fi first
#define se second
#define endl '\n'

int Get(int n) {
    // if (n < 0)
    //     return 1;
    return n / 4 + n / 7 + n / 11 - n / 28 - n / 77 - n / 44 + n / 308;
}

signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	#ifdef lan_ngu
		freopen((Fname + ".inp").c_str(), "r", stdin);
		freopen((Fname + ".out").c_str(), "w", stdout);
	#endif

	int _nt, l, r; cin >> _nt;
	// int _nt = 1;
	while (_nt--) {
		cin >> l >> r;
        cout << Get(r) - Get(max(0LL, l - 1)) + (l == 0) << endl;
	}
	
	return 0;
}