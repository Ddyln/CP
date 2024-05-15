#include <bits/stdc++.h>
using namespace std;

#define Fname ((string) "test")
#define ii pair <int, int>
#define iii pair <int, ii>
#define fi first
#define se second
#define endl '\n'
const int N = 1003;
const int INF = 1e9 + 7;
const int C = 11;
int n, m, a[N][N], f[N][C * N];

bool inside(int x, int y) {
    return (x >= 0 && x < m && y >= 0 && y < n);
}

bool hasRock(int x, int y, int t) {
    return a[(x + t) % m][y];
}
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
        cin >> m >> n;
        for (int i = 0; i < m; i++)
            for (int j = 0; j < n; j++)
                cin >> a[i][j];
        for (int i = 0; i < m; i++)
            for (int j = 0; j <= max(n, m) * C; j++)
                f[i][j] = -1;
        f[0][0] = 0;
        priority_queue <iii> q;
        q.push({0, {0, 0}});
        int res = INF;
        while (q.size()) {
            int x = q.top().se.fi, t = q.top().se.se, y = q.top().fi;
            q.pop();
            if (y != f[x][t]) continue;
            if (y == n - 1) {
                res = min(res, min(x + 1, m - x - 1) + t);
                continue;
            }
            if (!hasRock((x + 1) % m, y, t) && !hasRock((x + 2) % m, y, t)) {
                if (f[(x + 1) % m][t + 1] < y) {
                    f[(x + 1) % m][t + 1] = y;
                    q.push({y, {(x + 1) % m, t + 1}});
                }
            }
            if (!hasRock((x + 1) % m, (y + 1) % n, t)) {
                if (f[x][t + 1] < y + 1) {
                    f[x][t + 1] = y + 1;
                    q.push({y + 1, {x, t + 1}});
                }
            }
        }
        cout << (res == INF ? -1 : res) << endl;
	}
	
	return 0;
}