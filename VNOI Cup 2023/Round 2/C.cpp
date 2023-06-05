#include <bits/stdc++.h>
using namespace std;

#define Fname ((string) "test")
#define int long long
#define ii pair <int, int>
#define iii pair <int, ii>
#define fi first
#define se second
#define endl '\n'
const int N = 2e5 + 5;

int n, k, a[N], b[N];
map <int, int> pos1[N], pos2[N];
map <int, int> :: iterator it1, it2, it, itt;

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
        cin >> n >> k;
        for (int i = 1; i <= n; i++) {
            cin >> a[i];
            b[i] = a[i];
        }
        sort(b + 1, b + 1 + n);
        int m = unique(b + 1, b + 1 + n) - b - 1;
        for (int i = 1; i <= m; i++)
            pos1[i].clear(), pos2[i].clear();
        for (int i = 1; i <= n; i++) { 
            a[i] = lower_bound(b + 1, b + 1 + m, a[i]) - b;
            pos1[a[i]][i % k]++;
        }
        sort(a + 1, a + 1 + n);
        for (int i = 1; i <= n; i++)
            pos2[a[i]][i % k]++;
        bool ok = 1;
        for (int i = 1; i <= m; i++) {
            for (it = pos1[i].begin(); it != pos1[i].end(); it++) {
                it1 = pos2[i].lower_bound(it->fi);
                itt = pos1[i].end();
                int tmp = 0;
                if (k - it->fi != it->fi) {
                    itt = pos1[i].lower_bound(k - it->fi);
                    if (itt == pos1[i].end() || itt->fi != k - it->fi)
                        tmp = 0;
                    else
                        tmp = itt->se;
                }
                int x = 0, y = 0;
                if (it1 != pos2[i].end() && it1->fi == it->fi)
                    x = it1->se;
                if (it->fi != k - it->fi) {
                    it2 = pos2[i].lower_bound(k - it->fi);
                    if (it2 != pos2[i].end() && it2->fi == k - it->fi)
                        y = it2->se;
                }
                
                if (x + y < it->se + tmp) {
                    ok = 0;
                }
            }
        }
        cout << (ok ? "YES" : "NO") << endl;
	}
	
	return 0;
}