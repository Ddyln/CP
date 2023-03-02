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

int n, k, cnt[2][N][26], m, id[N];
string s, t;
queue <int> q;

void bfs(int u) {
    q.push(u);
    while (q.size()) {
        u = q.front();
        id[u] = m;
        q.pop();
        if (u + k <= n && !id[u + k]) {
            id[u + k] = m;
            q.push(u + k);
        }
        if (u + k + 1 <= n && !id[u + k + 1]) {
            id[u + k + 1] = m;
            q.push(u + k + 1);
        }
        if (u - k > 0 && !id[u - k]) {
            id[u - k] = m;
            q.push(u - k);
        }
        if (u - k - 1 > 0 && !id[u - k - 1]) {
            id[u - k - 1] = m;
            q.push(u - k - 1);
        }
    }
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
		// Code here
        cin >> n >> k >> s >> t;
        m = 0;
        memset(id, 0, sizeof(id));
        memset(cnt, 0, sizeof(cnt));
        for (int i = 1; i <= n; i++)
            if (!id[i]) {
                m++;
                bfs(i);
            }
        for (int i = 1; i <= n; i++) {
            cnt[0][id[i]][s[i - 1] - 'a']++;
            cnt[1][id[i]][t[i - 1] - 'a']++;
        }
        bool ok = 1;
        for (int i = 1; i <= m; i++) {
            for (int j = 0; j < 26; j++)
                if (cnt[0][i][j] != cnt[1][i][j])
                    ok = 0;
        }
        cout << (ok ? "YES\n" : "NO\n");
	}
	
	return 0;
}