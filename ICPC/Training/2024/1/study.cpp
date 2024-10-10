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

	// int _nt; cin >> _nt;
	int _nt = 1;
	while (_nt--) {
        cin >> n;
        for (int i = 1; i <= n; i++) {
            cin >> a[i];
            s1[i] = s1[i - 1] + a[i];
        }
        for (int i = 1; i <= n; i++) {
            cin >> b[i];
            s2[i] = s2[i - 1] + b[i];
        }
        for (int i = 1; i <= n; i++) {
            cin >> c[i];
            s3[i] = s3[i - 1] + 3[i];
        }
        for (int i = 1; i <= n; i++) {
            if (s1[i])
        }
	}
	
	return 0;
}