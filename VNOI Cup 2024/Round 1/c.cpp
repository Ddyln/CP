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
        freopen((Fname + ".inp").c_str(), "r", stdin);
        freopen((Fname + ".out").c_str(), "w", stdout);
    #endif

	int _nt; cin >> _nt;
	// int _nt = 1;
	while (_nt--) {
        int x;
        cin >> x;
        if (x == 1 || x == 2) {
            cout << (x == 1 ? "1\n1\n" : "2\n1 2\n");
            continue;
        }
        int k = 1;
        while ((k ^ 1) <= x) {
            k = (k << 1) | 1;
        }
        // cerr << k << ' ';
        k >>= 1;
        int sz = 0;
        x = k;
        while (k > 0) {
            k >>= 1;
            sz++;
        }
        k = x;
        cout << sz << endl;
        for (int i = 0; i < sz; i++)
            cout << (k ^ (1 << i)) << ' ';
        cout << endl;
	}
	
	return 0;
}