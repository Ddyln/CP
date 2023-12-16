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

int n, deg[N];

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
        memset(deg, 0, sizeof deg);
        for (int i = 1; i < n; i++) {
            int u, v; cin >> u >> v;
            deg[u]++;
            deg[v]++;
        }
        deg[0] = 1;
        for (int i = 1; i <= n; i++)
            if (deg[i] == 1)
                deg[0]++;
        cout << deg[0] / 2 << endl;
	}
	
	return 0;
}