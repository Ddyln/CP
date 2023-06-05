#include <bits/stdc++.h>
using namespace std;

#define Fname ((string) "test")
#define int long long
#define ii pair <int, int>
#define iii pair <int, ii>
#define fi first
#define se second
#define endl '\n'

bool check(vector <vector <int>> &a, int i, int j, int u, int v) {
    if (a[i][j] < v - j)
        return 0;
    if (a[i][v] < u - i)
        return 0;
    if (a[u][v] < v - j)
        return 0;
    if (a[u][j] < u - i)
        return 0;
    return 1;
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
        int n, m, res = 0;
        cin >> m >> n;
        vector <vector <int>> a(m + 3, vector <int> (n + 3, 0));
        for (int i = 1; i <= m; i++)
            for (int j = 1; j <= n; j++)
                cin >> a[i][j];
        int ok = 0;
        if (m * n <= 1000)
            ok = 1;
        for (int i = 1; i <= m; i++)
            for (int j = 1; j <= n; j++) {
                for (int u = i + 1; u <= (ok ? m : min(m, i + 11)); u++)
                    for (int v = j + 1; v <= (ok ? n : min(n, j + 11)); v++)
                        if (check(a, i, j, u, v))
                            res++;
            }
        cout << res;
	}
	
	return 0;
}