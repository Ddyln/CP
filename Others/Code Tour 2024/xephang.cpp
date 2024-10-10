#include <bits/stdc++.h>
using namespace std;

#define Fname ((string) "test")
#define ii pair <int, int>
#define iii pair <int, ii>
#define fi first
#define se second
#define endl '\n'

const int N = 1e6 + 1;

int n, h[N], q, Q[N], st[4 * N];

void update(int id, int l, int r, int pos) {
    if (r < pos || l > pos) return;
    if (l == r) {
        st[id]++;
        return;
    }
    int m = (l + r) / 2;
    update(id * 2, l, m, pos);
    update(id * 2 + 1, m + 1, r, pos);
    st[id] = st[id * 2] + st[id * 2 + 1];
}

int get(int id, int l, int r, int u, int v) {
    if (r < u || l > v) return 0;
    if (l >= u && r <= v) return st[id];
    int m = (l + r) / 2;
    return get(id * 2, l, m, u, v) + get(id * 2 + 1, m + 1, r, u, v);
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
        vector <int> v;
        for (int i = 1; i <= n; i++) {
            cin >> h[i];
            v.push_back(h[i]);
        }
        for (int i = 0; i < q; i++) {
            cin >> Q[i];
            v.push_back(Q[i]);
        }
        sort(v.begin(), v.end());
        int sz = unique(v.begin(), v.end()) - v.begin();
        for (int i = 1; i <= n; i++) {
            h[i] = upper_bound(v.begin(), v.begin() + sz, h[i]) - v.begin();
            update(1, 1, sz, h[i]);
        }
        for (int i = 0; i < q; i++) {
            Q[i] = upper_bound(v.begin(), v.begin() + sz, Q[i]) - v.begin();
            cout << get(1, 1, sz, 1, Q[i]) + 1 << endl;
            update(1, 1, sz, Q[i]);
        }
	}
	
	return 0;
}