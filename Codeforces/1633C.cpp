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
		int hc, dc, hm, dm, k, w, a;
		cin >> hc >> dc >> hm >> dm >> k >> w >> a;
		bool res = 0;
		for (int i = 0; i <= k && !res; i++) {
			int ndc = dc + i * w, nhc = hc + (k - i) * a;
			if ((hm - 1) / ndc + 1 <= (nhc - 1) / dm + 1) 
				res = 1;
		}		
		cout << (res ? "YES\n" : "NO\n");
	}

	return 0;
}