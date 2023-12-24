#include <bits/stdc++.h>
using namespace std;

#define Fname ((string) "test")
#define ii pair <int, int>
#define iii pair <int, ii>
#define fi first
#define se second
#define endl '\n'

const int N = 1e5 + 5;

int n;
bool f[N][26];
string s;

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
        cin >> n >> s;
        s = " " + s;
        memset(f, 0, sizeof f);
        for (int i = 1; i <= n; i++) {
            for (int j = 0; j < 26; j++)
                f[i][j] = (f[i - 1][j] || s[i] - 'a' == j);
        }

        int res = 0;
        for (int i = n; i > 0; i--) {
            for (int j = 0; j < 26; j++)
                if (f[i][j]) {
                    if (s[i - 1] != char(j + 'a'))
                        res++;
                }
            res++;
        }
        cout << res - 1 << endl;
	}
	
	return 0;
}