#include <bits/stdc++.h>
using namespace std;

#define Fname ((string) "test")
#define int long long
#define ii pair <int, int>
#define iii pair <int, ii>
#define fi first
#define se second
#define endl '\n'

void sol() {
    string s;
    cin >> s;
    bool ok = (s[0] == 'Y' || s[0] == 'e' || s[0] == 's');
    for (int i = 1; i < s.size() && ok; i++)
        if (s[i] == 's')
            ok = (s[i - 1] == 'e');
        else if (s[i] == 'e')
            ok = (s[i - 1] == 'Y');
        else if (s[i] == 'Y')
            ok = (s[i - 1] == 's');
        else
            ok = 0;
    cout << (ok ? "YES\n" : "NO\n");
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
	while (_nt--) {
        sol();
	}
	
	return 0;
}