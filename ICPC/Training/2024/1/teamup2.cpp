#include <bits/stdc++.h>
using namespace std;

#define Fname ((string) "test")
#define int long long
#define ii pair <int, int>
#define iii pair <int, ii>
#define fi first
#define se second
#define endl '\n'
const int N = 1e5 + 5;

int n, a[N], x[N], cnt[N][31];

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
        cin >> n;
        for (int i = 1; i <= n; i++) {
            cin >> a[i];
            x[i] = x[i - 1] ^ a[i];
            for (int k = 1; k <= 30; k++)
                cnt[i][k] = (cnt[i - 1][k] ^ (a[i] == k));
        }
        int res = 0;
        for (int k = 2; k <= 2; k++) {
            map <int, vector <int>> mp;
            for (int i = 1; i <= n; i++) {
                for (int j : mp[x[i] ^ k])
                    if (cnt[i][k] ^ cnt[j][k])
                        res = max(res, i - j);
                if (res == 4) cerr << i << endl;
                mp[x[i - 1]].push_back(i - 1);
            }
            cerr << res << endl;
        }
        cout << res;
	}
	
	return 0;
}