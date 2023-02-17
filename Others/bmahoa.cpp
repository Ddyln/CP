#include <bits/stdc++.h>
using namespace std;

#define Fname ((string) "test")
#define ii pair <int, int>
#define iii pair <int, ii>
#define fi first
#define se second
#define endl '\n'

const int N = 1e3 + 10;
int x, f[N];
string s, tmp;

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
        cin >> x >> s;
        if (s == "")
            return 0;
        int n = s.size();
        x %= f[n - 1];
        while (x--) {
            tmp = s;
            for (int i = 1; i <= n / 2; i++) {
                s[n - i] = tmp[i * 2 - 1];
                s[i] = tmp[i * 2];
            }
        }
        cout << s;
	}
	return 0;
}