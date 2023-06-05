#include <bits/stdc++.h>
using namespace std;

#define int long long
const int N = 1e2 + 3;
typedef pair <int, int> ii;

int X[N], Y[N], n, m, l, isBomb[N][N];
bool bombed[N][N], d[N][N], exploded[N];

bool inside(int x, int y) {
    return (x >= 0 && x <= n && y >= 0 && y <= n);
}

void bfs(int u) {
    queue <int> q;
    q.push(u);
    memset(bombed, 0, sizeof bombed);
    memset(exploded, 0, sizeof exploded);
    bombed[X[u]][Y[u]] = 1;
    exploded[u] = 1;
    while (q.size()) {
        u = q.front();
        q.pop();
        for (int dx = -l; dx <= l; dx++) 
            for (int dy = -l; dy <= l; dy++) {
                int nx = X[u] + dx, ny = Y[u] + dy;
                if (!inside(nx, ny))
                    continue;
                if (isBomb[nx][ny] && !exploded[isBomb[nx][ny]]) {
                    exploded[isBomb[nx][ny]] = 1;
                    q.push(isBomb[nx][ny]);
                }
                bombed[nx][ny] = 1;
            }
    }
}

void find(int x, int y) {
    memset(d, 0, sizeof d);
    if (bombed[x][y])
        return;
    queue <ii> q;
    q.push({x, y});
    int dx[] = {-1, 0, 1, 0},
        dy[] = {0, 1, 0, -1};
    while (q.size()) {
        x = q.front().first, y = q.front().second;
        q.pop();
        if (x == n && y == n)
            return;
        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i], ny = y + dy[i];
            if (!inside(nx, ny) || bombed[nx][ny])
                continue;
            if (!d[nx][ny]) {
                d[nx][ny] = 1;
                q.push({nx, ny});
            }
        }
    }
}

signed main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    freopen("test.inp", "r", stdin);
    int _t = 1;
    // int _t; cin >> _t;
    while (_t--) {
        cin >> n >> m >> l;
        for (int i = 1; i <= m; i++) {
            cin >> X[i] >> Y[i];
            isBomb[X[i]][Y[i]] = i;
        }
        queue <ii> ans;
        for (int i = 1; i <= m; i++) {
            bfs(i);
            find(0, 0);
            if (!d[n][n]) {    
                ans.push({X[i], Y[i]});
            }
        }
        cout << ans.size() << endl;
        while (ans.size()) {
            cout << ans.front().first << ' ' << ans.front().second << endl;
            ans.pop();
        }
    }
    return 0;
}
