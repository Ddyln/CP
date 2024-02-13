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

int n, k;
vector <int> v[N];

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
        cin >> n >> k;
        bool res = 1;
        v[0].clear();
        for (int id = 1; id <= k; id++) {
            v[id].clear();
            for (int j = 1; j <= n; j++) {
                int a; cin >> a;
                v[id].push_back(a);
            }
        
            if (id > 1) {
                bool ok = 1;
                int i = 1, j = 1;
                while (i < n || j < n) {
                    if (v[1][i] == v[id][0]) i++;
                    if (v[id][j] == v[1][0]) j++;
                    if (i == n || j == n) break;
                    if (v[1][i] != v[id][j]) {
                        ok = 0;
                        // cout << id << ' ' << i << ' ' << j << endl;
                        break;
                    }
                    i++, j++;
                }
                if (!ok) res = 0;
            }
        }
        for (int i = 1; n > 1 && i <= k; i++)
            v[0].push_back(v[i][1]);
        sort(v[0].begin(), v[0].end());
        if (v[0].size() > 1) {
            int cnt = 0, xx = 1;
            for (int i = 1; i < v[0].size(); i++)
                if (v[0][i] != v[0][i - 1])
                    cnt++;
            for (int i = 1; i < v[0].size(); i++)
                if (v[0][i] != v[0][i - 1])
                    break;
                else    
                    xx++;
            if (!(cnt == 1 && (xx == 1 || xx + 1 == v[0].size()) || cnt == 0)) res = 0;
        }
        cout << (res ? "YES\n" : "NO\n");
	}
	
	return 0;
}