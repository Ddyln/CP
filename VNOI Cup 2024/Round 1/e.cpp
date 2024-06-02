#include <bits/stdc++.h>
using namespace std;

#define Fname ((string) "test")
#define ii pair <int, int>
#define iii pair <int, ii>
#define fi first
#define se second
#define endl '\n'

int x[3], y[3], n, c[3], l[3];
map <ii, int> mp;

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
        if (n > 2) continue;
        mp.clear();
        int res = 0;
        for (int i = 1; i <= n; i++)
            cin >> x[i] >> y[i] >> l[i] >> c[i];
        mp[{x[1], y[1]}]++;
        for (int i = 1; i <= l[1]; i++) {
            int nx, ny;
            if (c[1] == 0)
                nx = x[1] + (i + 1) / 2, ny = y[1] + i / 2;
            else 
                nx = x[1] + i / 2, ny = y[1] + (i + 1) / 2;
            mp[{nx, ny}] = 1;
        }
        if (mp.find({x[2], y[2]}) != mp.end()) res++;
        for (int i = 1; i <= l[2]; i++) {
            int nx, ny;
            if (c[2] == 0)
                nx = x[2] + (i + 1) / 2, ny = y[2] + i / 2;
            else 
                nx = x[2] + i / 2, ny = y[2] + (i + 1) / 2;
            if (mp.find({nx, ny}) != mp.end()) res++;
        } 
        cout << res << endl;
	}
	
	return 0;
}