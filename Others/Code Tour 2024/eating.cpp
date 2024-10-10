#include <bits/stdc++.h>
using namespace std;

#define Fname ((string) "test")
#define int long long
#define ii pair <int, int>
#define iii pair <int, ii>
#define fi first
#define se second
#define endl '\n'
const int INF = 3e18;
const int N = 2e5 + 4;

class SegmentTree {
public: 
    int *st, n;
    SegmentTree() {
        n = 0;
        st = nullptr;
    }

    SegmentTree(int sz) {
        n = sz;
        st = new int[4 * n];
        for (int i = 1; i < 4 * n; i++)
            st[i] = INF;
    }
    int cnt = 0;

    void update(int id, int l, int r, int pos, int val) {
        if (r < pos || l > pos) return;
        if (l == r) {
            st[id] = val;
            return;
        }
        int m = (l + r) / 2;
        update(id * 2, l, m, pos, val);
        update(id * 2 + 1, m + 1, r, pos, val);
        st[id] = min(st[id * 2], st[id * 2 + 1]);
    }

    void update(int pos, int val) {
        update(1, 1, n, pos, val);
    }

    int get(int id, int l, int r, int u, int v) {
        if (r < u || l > v) return INF;
        if (l >= u && r <= v) return st[id];
        int m = (l + r) / 2;
        return min(get(id * 2, l, m, u, v), get(id * 2 + 1, m + 1, r, u, v)); 
    }

    int get(int l, int r) {
        return get(1, 1, n, l, r);
    }
};

int n, a[N], pre[N], suf[N];

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
        cin >> n;
        SegmentTree A(n);
        a[n + 1] = 0;
        for (int i = 1; i <= n; i++) 
            cin >> a[i];
        for (int i = 1; i <= n; i++) {
            pre[i] = pre[i - 1] + a[i];
            A.update(i, pre[i] - a[i + 1]);
        }
        SegmentTree B(n);
        suf[n + 1] = 0;
        for (int i = n; i > 0; i--) {
            suf[i] = suf[i + 1] + a[i];
            B.update(i, suf[i] - a[i - 1]);
        }
        bool ok = 0;
        for (int i = 1; i <= n; i++) {
            if (a[i] > 1) continue;
            if (!(i == n || A.get(i, n) + 1 >= pre[i - 1]))
                continue;
            int cur = pre[n] - pre[i - 1] + 1;
            if (!(i == 1 || (cur >= a[i - 1] && cur + B.get(1, i - 1) >= suf[i])))
                continue;
            ok = 1;
            break;
        }
        cout << (ok ? "YES\n" : "NO\n");
	}
	
	return 0;
}