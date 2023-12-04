#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 3;

int n, k, q, a[N], pos[N];
vector <vector <int>> st;

void Build(int id, int l, int r) {
    if (l == r) {
        st[id].push_back(a[l]);
        return;
    }
    int m = (l + r) / 2;
    Build(id * 2, l, m);
    Build(id * 2 + 1, m + 1, r);
    merge(st[id * 2].begin(), st[id * 2].end(), st[id * 2 + 1].begin(), st[id * 2 + 1].end(), back_inserter(st[id]));
}

int Find(int id, int l, int r, int u, int v, int val) {
    if (r < u || l > v)
        return 0;
    if (l >= u && r <= v) {
        return upper_bound(st[id].begin(), st[id].end(), val) - st[id].begin();
    }
    int m = (l + r) / 2;
    return Find(id * 2, l, m, u, v, val) + Find(id * 2 + 1, m + 1, r, u, v, val);
}

int cnp(int l, int r, int u, int v, int k) {

    int ans;
    while (l <= r) {
        int m = (l + r) / 2, tmp;
        tmp = Find(1, 1, n, u, v, m);

        if (tmp >= k) {
            ans = m;
            r = m - 1;
        } else l = m + 1;
    }
    return ans;
}

signed main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    if(fopen("test.inp", "r"))
    {
        freopen("test.inp", "r", stdin);
        freopen("test.out", "w", stdout);
    }
    cin >> n >> q >> k;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        pos[a[i]] = i;
    }
    st.resize(4 * n + 4);
    Build(1, 1, n);

    stack <pair <int, int>> s;
    while (q--) {
        int l, r;
        cin >> l >> r;
        s.push({l, r});
    }

    while (s.size()) {
        int l = s.top().first, r = s.top().second;
        s.pop();
        if (r < k || l > k)
            continue;
        k = pos[cnp(1, n, 1, r - l + 1, k - l + 1)] + l - 1;
    }
    cout << k;
    return 0;
}
