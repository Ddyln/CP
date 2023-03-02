#include <bits/stdc++.h>
using namespace std;

#define Fname ((string) "test")
#define int long long
#define ii pair <int, int>
#define iii pair <int, ii>
#define fi first
#define se second
#define endl '\n'

bool check(int cnt, char s, char t) {
    // cerr << cnt << ' ' << s << ' ' << t << endl;
    if (cnt == 0 && s == 'M' && t == 'E')
        return 1;
    if (cnt == 1 && s == 'E' && t == 'O')
        return 1;
    if (cnt == 2 && s == 'O' && t == 'W')
        return 1;
    return 0;
}

signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	#ifdef lan_ngu
		freopen((Fname + ".inp").c_str(), "r", stdin);
		freopen((Fname + ".out").c_str(), "w", stdout);
	#endif

	int _nt; cin >> _nt;
	// int _nt = 1;
    string s;
    int n = 0;
	while (_nt--) {
		cin >> n >> s;
        int cnt = 0, ok = (toupper(s[0]) == 'M');
        for (int i = 1; i < s.size(); i++) {
            if (toupper(s[i]) != toupper(s[i - 1])) {
                ok &= (check(cnt, toupper(s[i - 1]), toupper(s[i])));
                cnt++;
            }
        }
        ok &= (toupper(s[n - 1]) == 'W');
        cout << (ok ? "YES" : "NO") << endl;
	}
	
	return 0;
}