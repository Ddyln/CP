#include <bits/stdc++.h>
using namespace std;

#define Fname ((string) "test")
#define int long long
#define ii pair <int, int>
#define iii pair <int, ii>
#define fi first
#define se second
#define endl '\n'

const int N = 104;
int n, a[N];

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
        cin >> n;
        for (int i = 1; i <= n; i++) 
            cin >> a[i];
        for (int res = 2;; res <<= 1) {
            map <int, int> mp;
            for (int i = 1; i <= n; i++) {
                mp[a[i] % res]++;
                if (mp.size() > 2)
                    break;
            }
            if (mp.size() == 2) {
                cout << res << endl;
                break;
            }
        }
	}
	
	return 0;
}