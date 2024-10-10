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
const int INF = 1e18;

int n, st[4 * N], lazy[4 * N], t[N], ll[N], lr[N], rl[N], rr[N], f[N];
vector <int> open[N], close[N];

void update(int id, int l, int r, int pos, int x) {
    if (r < pos || l > pos) return;
    if (l == r) {
        st[id] = x;
        return;
    }
    int m = (l + r) / 2;
    update(id * 2, l, m, pos, x);
    update(id * 2 + 1, m + 1, r, pos, x);
    st[id] = min(st[id * 2], st[id * 2 + 1]);
}

int get(int id, int l, int r, int u, int v) {
    if (r < u || l > v) return INF;
    if (l >= u && r <= v) return st[id];
    int m = (l + r) / 2;
    return min(get(id * 2, l, m, u, v), get(id * 2 + 1, m + 1, r, u, v));
}

void build(int id, int l, int r) {
    st[id] = INF;
    if (l == r) return;
    int m = (l + r) / 2;
    build(id * 2, l, m);
    build(id * 2 + 1, m + 1, r);
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
        cin >> n;
        for (int i = 1; i <= n; i++) 
            cin >> t[i] >> ll[i] >> lr[i] >> rl[i] >> rr[i];
        build(1, 1, n);
        f[1] = t[1];
        if (rl[1] == 1 && rr[1] > 1) update(1, 1, n, 1, f[1]);
        open[rl[1]].push_back(1);
        close[rr[1]].push_back(1);
        for (int i = 2; i <= n; i++) {
            for (int id : open[i])
                update(1, 1, n, id, f[id]);
            for (int id : close[i - 1]) 
                update(1, 1, n, id, INF);
            f[i] = get(1, 1, n, ll[i], lr[i]);
            if (f[i] == INF) {
                cout << "-1 ";
            }
            else {
                cout << f[i] + t[i] + i - 1 << ' ';
                f[i] += 2 * t[i];
            }
            if (rl[i] == i && rr[i] > i) update(1, 1, n, i, f[i]);
            open[rl[i]].push_back(i);
            close[rr[i]].push_back(i);
        }
	}
	
	return 0;
}