#include <bits/stdc++.h>
using namespace std;

#define Fname ((string) "test")
#define int long long
#define ii pair <int, int>
#define iii pair <int, ii>
#define fi first
#define se second
#define endl '\n'

const int INF = 1e9 + 7;
const int N = 1e5 + 5;
const int def = -1;

int n, q, a[N], st[4 * N], lazy[4 * N];

void build(int id, int l, int r) {
    lazy[id] = def;
    if (l == r) {
        st[id] = a[l];
        return;
    }
    int m = (l + r) / 2;
    build(id * 2, l, m);
    build(id * 2 + 1, m + 1, r);
    st[id] = min(st[id * 2], st[id * 2 + 1]);
}

void down(int id) {
    lazy[id * 2] &= lazy[id];
    lazy[id * 2 + 1] &= lazy[id];
    st[id * 2] &= lazy[id];
    st[id * 2 + 1] &= lazy[id];
    lazy[id] = def;
}

void update(int id, int l, int r, int u, int v, int x) {
    if (r < u || l > v) return;
    if (l >= u && r <= v) {
        lazy[id] &= x;
        st[id] &= x;
        return;
    }
    down(id);
    int m = (l + r) / 2;
    update(id * 2, l, m, u, v, x);
    update(id * 2 + 1, m + 1, r, u, v, x);
    st[id] = min(st[id * 2], st[id * 2 + 1]);
}

int get(int id, int l, int r, int u, int v) {
    if (r < u || l > v) return INF;
    if (l >= u && r <= v) return st[id];
    int m = (l + r) / 2;
    down(id);
    return min(get(id * 2, l, m, u, v), get(id * 2 + 1, m + 1, r, u, v));
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
        cin >> n >> q;
        for (int i = 1; i <= n; i++) 
            cin >> a[i];
        build(1, 1, n);
        while (q--) {
            int t, l, r;
            cin >> t >> l >> r;
            if (!t) {
                int x; cin >> x;
                update(1, 1, n, l, r, x);
            }
            else
                cout << get(1, 1, n, l, r) << endl;
        }
	}
	
	return 0;
}