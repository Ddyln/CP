#include <bits/stdc++.h>
using namespace std;

#define Fname ((string) "test")
#define int long long
#define ii pair <int, int>
#define iii pair <int, ii>
#define fi first
#define se second
#define endl '\n'

int n, k, cnt[26][2];
string s;

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
		// Code here
        cin >> n >> k >> s;
        memset(cnt, 0, sizeof(cnt));
        for (char c : s)
            cnt[toupper(c) - 'A'][c == toupper(c)]++;
        int res = 0;
        for (int i = 0; i < 26; i++) {
            res += min(cnt[i][0], cnt[i][1]);
            int tmp = abs(cnt[i][0] - cnt[i][1]);
            res += min(tmp / 2, k);
            k -= min(k, tmp / 2);
        }
        cout << res << endl;
	}
	
	return 0;
}