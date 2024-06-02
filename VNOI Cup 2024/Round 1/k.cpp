#include <bits/stdc++.h>
using namespace std;

#define Fname ((string) "test")
#define int long long
#define ii pair <int, int>
#define iii pair <int, ii>
#define fi first
#define se second
#define endl '\n'

map <string, int> mp;
int n, k;
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
    cin >> k;
	while (_nt--) {
        cin >> n >> s;
        mp.clear();
        int res = 0;
        for (int mask = 1; mask < (1 << n); mask++) {
            string cur = "";
            for (int i = 0; i < n; i++)
                if (mask & (1 << i))
                    cur += s[i];
            mp[cur]++;
        }
        for (auto it = mp.begin(); it != mp.end(); it++)
            if (it->se == k)
                res++;
        cout << res << endl;
	}
	
	return 0;
}