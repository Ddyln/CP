#include <bits/stdc++.h>
using namespace std;

#define Fname ((string) "test")
#define int long long
#define ii pair <int, int>
#define iii pair <int, ii>
#define fi first
#define se second
#define endl '\n'

char get(int n) {
    return (int)'a' + --n;
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
        int n, ok = 1;
        string ans = "";
        cin >> n;
        for (int i = 1; i <= 26 && ok; i++)
            for (int j = 1; j <= 26 && ok; j++) {
                if (n - i - j > 0 && n - i - j <= 26) {
                    ans = get(i);
                    ans += get(j);
                    ans += get(n - i - j);
                    ok = 0;
                }
            }
        cout << ans << endl;
	}
	
	return 0;
}