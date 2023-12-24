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
        freopen("test.inp", "r", stdin);
        freopen("test.out", "w", stdout);
    #endif

	int _nt; cin >> _nt;
	// int _nt = 1;
	while (_nt--) {
        int n, tmp = 0;
        bool cnt = 0;
        cin >> n;
        for (int i = 1; i <= n; i++) {
            int a; cin >> a;
            if (a < 0) cnt ^= 1;
            if (a == 0) 
                tmp++;
        }
        if (cnt || tmp)
            cout << "0\n";
        else 
            cout << "1\n1 0\n";
	}
	
	return 0;
}