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
        string s;
        cin >> s;
        int n = s.size();
        s = " " + s;
        int cnt0 = 0, cnt1 = 0;
        for (int i = 1; i <= n; i++) {
            cnt0 += (s[i] == '0');
            cnt1 += (s[i] == '1');
        }
        int x = 0, y = 0, res = n;
        for (int i = 1; i <= n; i++) {
            x += (s[i] == '1');
            y += (s[i] == '0');
            if (x > cnt0 || y > cnt1)
                break;
            res = min(res, cnt0 - x + cnt1 -  y);
        }
        cout << res << endl;
	}
	
	return 0;
}