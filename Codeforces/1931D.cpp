#include <bits/stdc++.h>
using namespace std;

#define Fname ((string) "test")
#define int long long
#define ii pair <int, int>
#define iii pair <int, ii>
#define fi first
#define se second
#define endl '\n'
const int N = 2e5 + 5;

int n, x, y, a;
map <int, int> mp;

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
        cin >> n >> x >> y;
        int s = x * y / __gcd(x, y), res = 0;
        mp.clear();
        for (int i = 1; i <= n; i++) {
            cin >> a;
            res += mp[(s - a % s) % s];
            mp[a % s]++;
        }
        cout << res << endl;
	}
	
	return 0;
}