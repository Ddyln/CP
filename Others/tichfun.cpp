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
	while (_nt--) {
		// Code here
        int a, m, k;
        cin >> a >> m >> k;
        int numer = k * k, deno = 4 * (a * a + m * m);
        int tmp = __gcd(numer, deno);
        numer /= tmp, deno /= tmp;
        cout << numer << ' ' << deno << endl;
	}
	
	return 0;
}