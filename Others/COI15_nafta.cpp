// https://oj.uz/problem/view/COI15_nafta
#include <bits/stdc++.h>
using namespace std;
 
const int N = 2005;
typedef pair <int, int> ii;
#define fi first
#define se second
 
int n, m, sumReg, val[N], f[N][N], c[N][N];
char a[N][N];
bool vis[N][N];
int fx[] = {-1, 0, 1, 0},
    fy[] = {0, 1, 0, -1};
queue <ii> q;
 
ii bfs(int x, int y) {
    q.push({x, y});
    int l = y, r = y;
    vis[x][y] = 1;
    sumReg = 0;
    while (q.size()) {
        x = q.front().fi, y = q.front().se;
        q.pop();
        sumReg += a[x][y] - '0';
        for (int i = 0; i < 4; i++) {
            int nx = x + fx[i], ny = y + fy[i];
            if (!vis[nx][ny]) {
                l = min(l, ny);
                r = max(r, ny);
                vis[nx][ny] = 1;
                q.push({nx, ny});
            }
        }
    }
    return {l, r};
}
 
void cal(int i, int l, int r, int optL, int optR) {
    if (l > r) 
        return;
    int mid = (l + r) / 2, p;
    for (int j = optL; j <= min(mid, optR); j++)
        if (f[i][mid] < f[i - 1][j - 1] + c[j][mid]) {
            f[i][mid] = f[i - 1][j - 1] + c[j][mid];
            p = j;
        }
    cal(i, l, mid - 1, optL, p);
    cal(i, mid + 1, r, p, optR);
}
 
signed main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    // freopen("nhap.inp", "r", stdin);
    cin >> n >> m;
    for (int i = 0; i <= m + 1; i++)
        vis[0][i] = vis[n + 1][i] = 1;
    for (int i = 0; i <= n + 1; i++)
        vis[i][0] = vis[i][m + 1] = 1;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++) {
            cin >> a[i][j];
            vis[i][j] = (a[i][j] == '.');
        }
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            if (!vis[i][j]) {
                ii tmp = bfs(i, j);
                c[tmp.fi][tmp.se] += sumReg;
            }
    
    for (int d = m - 1; d >= 0; d--) 
        for (int i = 1; i + d <= m; i++) {
            int j = i + d;
            c[i][j] += c[i - 1][j];
        }
 
    for (int i = 1; i < m; i++)
        for (int j = i + 1; j <= m; j++)
            c[i][j] += c[i][j - 1];
    
    for (int i = 1; i <= m; i++) {
        cal(i, 1, m, 1, m);
        cout << f[i][m] << endl;
        // for (int j = 1; j <= m; j++)
        //     cout << f[i][j] << ' ';
    }
    return 0;
}