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
        if (s[0] == '0') {
            cout << "-1\n";
            continue;
        }
        int n = s.size(), x = -1;
        for (int i = 1; i < n; i++)
            if (s[i] != '0') {
                x = i;
                break;
            }
        if (x < 0) {
            cout << "-1\n";
            continue;
        }
        int l1 = x, l2 = n - x;
        if (l1 < l2) {
            cout << s.substr(0, x) << ' ' << s.substr(x, l2) << endl;
        }
        else if (l1 > l2) {
            cout << "-1\n";
        }
        else if (s.substr(0, x) < s.substr(x, l2)) {
            cout << s.substr(0, x) << ' ' << s.substr(x, l2) << endl;
        }
        else {
            cout << "-1\n";
        }
	}
	
	return 0;
}