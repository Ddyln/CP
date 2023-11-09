#include <bits/stdc++.h>
using namespace std;

#define Fname ((string) "test")
#define int long long
#define ii pair <int, int>
#define iii pair <int, ii>
#define fi first
#define se second
#define endl '\n'

signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	#ifdef lan_ngu
        freopen("test.inp", "w", stdout);
        // freopen("test.out", "w", stdout);
    #else
        freopen((Fname + ".inp").c_str(), "w", stdin);
        // freopen((Fname + ".out").c_str(), "w", stdout);
    #endif

	// int _nt; cin >> _nt;
	int _nt = 1;
	while (_nt--) {
		// Code here
        int n = 100;
        cout << n << endl;
        for (int i = 1; i <= n; i++)
            cout << "1 3 " << i << endl;
	}
	
	return 0;
}