#include <bits/stdc++.h>
using namespace std;

#define Fname ((string) "test")
#define ii pair <int, int>
#define iii pair <int, ii>
#define fi first
#define se second
#define endl '\n'

int n;
map <int, int> mp;

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
        cin >> n;
        mp.clear();
        for (int i = 1; i <= n; i++) {
            int tmp; cin >> tmp;
            mp[tmp]++;
        }
        int res = mp.size();
        for (int i = 1; i <= n; i++)
            cout << res + max(0, i - res) << ' ';
        cout << endl;
	}
	
	return 0;
}