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
        string s;
        int n = 0;
        cin >> n >> s;
        int a = 0, b = 0, cnt[26][2];
        for (int i = 0; i < 26; i++)
            cnt[i][0] = cnt[i][1] = 0;
        for (int i = 0; i < n; i++) 
            b += (++cnt[s[i] - 'a'][0] == 1);
        int res = b;
        for (int i = 0; i < n; i++) {
            a += (++cnt[s[i] - 'a'][1] == 1);
            b -= (--cnt[s[i] - 'a'][0] == 0);
            res = max(res, a + b);
        }
        cout << res << endl;
	}
	
	return 0;
}