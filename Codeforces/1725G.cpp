#include <bits/stdc++.h>
using namespace std;

#define Fname ((string) "test")
#define int unsigned int
#define ii pair <int, int>
#define iii pair <int, ii>
#define fi first
#define se second
#define endl '\n'

int n;

bool check(int x) {
    int odd = (x + 1) / 2;
    int even = x - odd;
    int other = even - (x / 2 + 1) / 2 - (x >= 4);
    cout << odd << ' ' << even << ' ' << other << endl;
    return (odd - 1 + other >= n);
}

int cnp(int l, int r) {
    if (l == r)
        return l;
    int m = (l + r) / 2;
    return (check(m) ? cnp(l, m) : cnp(m + 1, r));
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
		cin >> n;
        cout << check(8);
        // cout << cnp(1, 2e9);
	}
	
	return 0;
}