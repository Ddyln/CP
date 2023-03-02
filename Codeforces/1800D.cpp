#include <bits/stdc++.h>
using namespace std;

#define Fname ((string) "test")
#define int long long
#define ii pair <int, int>
#define iii pair <int, ii>
#define fi first
#define se second
#define endl '\n'

int n, res, cnt;
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
        cin >> n >> s;
        cnt = 1;
        res = n - 1;
        for (int i = 1; i < n; i++)
            if (s[i] == s[i - 1])
                cnt++;
            else {
                res -= max(0LL, cnt - 2);
                cnt = 1;
                if (i - 2 >= 0 && s[i] == s[i - 2])
                    res--;
            }
        res -= max(0LL, cnt - 2);
        cout << res << endl;
	}
	
	return 0;
}