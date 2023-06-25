#include <bits/stdc++.h>
using namespace std;
int MOD = 1e9 + 7;
vector <vector <int>> f, vis;
int dfs(vector<int>& locations, int& u, int& finish, int fuel) {
    if (vis[u][fuel])
        return f[u][fuel];
    vis[u][fuel] = 1;
    f[u][fuel] = (u == finish);
    if (fuel == 0)
        return f[u][fuel];
    for (int v = 0; v < locations.size(); v++)
        if (v != u && fuel - abs(locations[u] - locations[v]) >= 0) {
            (f[u][fuel] += dfs(locations, v, finish, fuel - abs(locations[u] - locations[v]))) %= MOD;
        }
    return f[u][fuel];
}

int countRoutes(vector<int>& locations, int start, int finish, int fuel) {
    f.resize(locations.size(), vector <int> (fuel + 1, 0));
    vis.resize(locations.size(), vector <int> (fuel + 1, 0));
    return dfs(locations, start, finish, fuel);
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    #ifdef lan_ngu
        freopen("test.inp", "r", stdin);
        freopen("test.out", "w", stdout);
    #endif
    vector <int> locations = {22,74,92,86,12,68,64,19,79,10,69,13,62,18,87,88,33,96,78,73,57,42,91,17,55,26,27,67,60,46,72,41};
    countRoutes(locations, 30, 29, 47);
    return 0;
}
