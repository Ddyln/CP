#include <bits/stdc++.h>
using namespace std;

#define Fname ((string) "test")
// #define int long long
#define ii pair <int, int>
#define iii pair <int, ii>
#define fi first
#define se second
#define endl '\n'
const int N = 2e5 + 5;
const int MASK = (1 << 26) - 1;

int n, a[N], tmp[26];
long long res = 0;
map <int, int> cnt;
vector <int> v[26];

int Get(int miss, int n) {
    return (((~n) & MASK) ^ (1 << miss));
}

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
		// Code here
        cin >> n;
        for (int i = 1; i <= n; i++) {
            string s;
            cin >> s;
            memset(tmp, 0, sizeof(tmp));
            for (char c : s) {
                a[i] ^= (1 << (c - 'a'));
                tmp[c - 'a']++;
            }
            for (int j = 0; j < 26; j++)
                if (tmp[j] == 0)
                    v[j].push_back(a[i]);
        }
        for (int i = 0; i < 26; i++) {
            cnt.clear();
            for (int x : v[i]) {
                res += 1LL * cnt[Get(i, x)];
                cnt[x]++;
            }
        }
        cout << res;
	}
	
	return 0;
}