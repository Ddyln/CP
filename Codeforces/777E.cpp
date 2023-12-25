#include <bits/stdc++.h>
using namespace std;

#define Fname ((string) "test")
#define ll long long
#define ii pair <int, int>
#define iii pair <int, ii>
#define fi first
#define se second
#define endl '\n'

const int N = 1e5 + 5;
struct RING {
    int x, y;
    ll val;
};

int n;
RING a[N];
struct SegmentTree {
    vector <ll> st;
    int n = 0;

private:
    ll get(int id, int l, int r, int u, int v) {
        if (r < u || l > v || u > v)
            return 0;
        if (l >= u && r <= v)
            return st[id];
        int m = (l + r) >> 1;
        return max(get(id << 1, l, m, u, v), get((id << 1) + 1, m + 1, r, u, v));
    }

    void update(int id, int l, int r, int pos, ll val) {
        if (r < pos || l > pos)
            return;
        if (l == r) {
            st[id] = max(st[id], val);
            return;
        }
        int m = (l + r) >> 1;
        update(id << 1, l, m, pos, val);
        update((id << 1) + 1, m + 1, r, pos, val);
        st[id] = max(st[id << 1], st[(id << 1) + 1]);
    }
public:
    SegmentTree(int n) {
        this-> n = n;
        st.resize(n * 4 + 3, 0);
    }

    ll get(int l, int r) {
        return get(1, 1, n, l, r);
    }

    void update(int pos, ll val) {
        update(1, 1, n, pos, val);
    }
};

bool cmp(const RING& a, const RING& b) {
    if (a.y != b.y)
        return a.y > b.y;
    else    
        return a.x > b.x;
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
        vector <int> v;
        for (int i = 1; i <= n; i++) {
            cin >> a[i].x >> a[i].y >> a[i].val;
            v.push_back(a[i].x);
            v.push_back(a[i].y);
        }
        sort(a + 1, a + 1 + n, cmp);
        sort(v.begin(), v.end());
        int sz = unique(v.begin(), v.end()) - v.begin();
        for (int i = 1; i <= n; i++) {
            a[i].x = lower_bound(v.begin(), v.begin() + sz, a[i].x) - v.begin() + 1;
            a[i].y = lower_bound(v.begin(), v.begin() + sz, a[i].y) - v.begin() + 1;
        }
        SegmentTree st(sz);
        ll res = 0;
        for (int i = 1; i <= n; i++) {
            ll tmp = st.get(1, a[i].y - 1) + a[i].val;
            res = max(res, tmp);
            st.update(a[i].x, tmp);
        }
        cout << res;
	}
	
	return 0;
}