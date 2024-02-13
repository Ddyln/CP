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

int n, a[N], s, have;
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
        cin >> n;
        s = have = 0;
        for (int i = 1; i <= n; i++) {
            cin >> a[i];
            s += a[i];
        }
        s /= n;
        bool ok = 1;
        for (int i = 1; i <= n; i++) {
            if (a[i] < s) {
                if (s - a[i] > have)
                   ok = 0;
                else
                    have -= s - a[i];
            }
            else
                have += a[i] - s;
        }
        cout << (ok ? "YES\n" : "NO\n");
	}
	
	return 0;
}