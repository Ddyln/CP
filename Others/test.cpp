#include <bits/stdc++.h>
using namespace std;

#define int long long

const int N = 1e4;
const int mxa = 3e4;
struct Line {
    int x, l, r, type;
};

int n, m, st[4 * mxa][2], lazy[4 * mxa];
Line a[N << 1];

bool cmp(const Line& a, const Line& b) {
    return (a.x == b.x ? a.type < b.type : a.x < b.x);
}

void down(int id, int l, int r) {
    int m = (l + r) >> 1;
    lazy[id << 1] += lazy[id];
    lazy[(id << 1) + 1] += lazy[id];
    st[id << 1][1] += lazy[id];
    st[(id << 1) + 1][1] += lazy[id];
    st[id << 1][0] = (m - l + 1) * max(1LL, st[id << 1][1]);
    st[(id << 1) + 1][0] = (r - m) * max(1LL, st[(id << 1) + 1][1]);
    lazy[id] = 0;
}

void update(int id, int l, int r, int u, int v, int val) {
    if (r < u || l > v)
        return;
    if (l >= u && r <= v) {
        lazy[id] += val;
        st[id][1] += val;
        st[id][0] = (r - l + 1) * max(1LL, st[id][1]); 
        return;
    }
    down(id, l, r);
    int m = (l + r) >> 1;
    update(id << 1, l, m, u, v, val);
    update((id << 1) + 1, m + 1, r, u, v, val);
    st[id][0] = st[id << 1][0] + st[(id << 1) + 1][0];
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    #ifdef lan_ngu
        freopen("test.inp", "r", stdin);
        freopen("test.out", "w", stdout);
    #endif

    cin >> n;
    for (int i = 1; i <= n; i++) {
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        a[(i << 1) - 1] = {x1, y1 , y2, 1};
        a[i << 1] = {x2, y1 , y2, -1};
        m = max(m, y2);
    }
    sort(a + 1, a + 1 + (n << 1), cmp);
    int res = 0;
    for (int i = 1; i < (n << 1); i++) {
        update(1, 1, m, a[i].l, a[i].r, a[i].type);
        res += st[1] * (a[i + 1].x - a[i].x);
        cout << res << endl;
    }
    cout << res;
    return 0;
}