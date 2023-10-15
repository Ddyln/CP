#include <bits/stdc++.h>
using namespace std;

#define Fname ((string) "test")
#define fi first
#define se second
#define endl '\n'

const int N = 1e6 + 5;

int n, m, a[N], b[N], p[N], st[8 * N];

void dnq(int li, int ri, int lp, int rp) {
    if (li > ri)
        return;
    int m = (li + ri) >> 1, inv = 0;
    for (int i = lp; i < rp; i++)
        inv += (a[i] > b[m]);
    int minInv = inv;
    p[m] = rp;
    for (int i = rp - 1; i >= lp; i--) {
        if (a[i] > b[m])
            inv--;
        else if (a[i] < b[m])
            inv++;
        if (inv < minInv) {
            minInv = inv;
            p[m] = i;
        }
    }
    dnq(li, m - 1, lp, p[m]);
    dnq(m + 1, ri, p[m], rp);
}

void update(int id, int l, int r, int pos, int val) {
    if (r < pos || l > pos)
        return;
    if (l == r) {
        st[id] += val;
        return;
    }
    int m = (l + r) >> 1;
    update(id << 1, l, m, pos, val);
    update((id << 1) + 1, m + 1, r, pos, val);
    st[id] = st[id << 1] + st[(id << 1) + 1];
}

int get(int id, int l, int r, int u, int v) {
    if (r < u || l > v || u > v)
        return 0;
    if (l >= u && r <= v)
        return st[id];
    int m = (l + r) >> 1;
    return get(id << 1, l, m, u, v) + get((id << 1) + 1, m + 1, r, u, v);
}

void make(int id, int l, int r) {
    st[id] = 0;
    if (l == r)
        return;
    int m = (l + r) >> 1;
    make(id << 1, l, m);
    make((id << 1) + 1, m + 1, r);
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
        cin >> n >> m;
        vector <int> v;
        for (int i = 1; i <= n; i++) {
            cin >> a[i];
            v.push_back(a[i]);
        }
        for (int i = 1; i <= m; i++) {
            cin >> b[i];
            v.push_back(b[i]);
        }
        
        sort(v.begin(), v.end());
        int sz = unique(v.begin(), v.end()) - v.begin();
        long long inv = 0;
        make(1, 1, sz);
        for (int i = 1; i <= n; i++) {
            a[i] = lower_bound(v.begin(), v.begin() + sz, a[i]) - v.begin() + 1;
            inv += 1LL * get(1, 1, sz, a[i] + 1, sz);
            update(1, 1, sz, a[i], 1);
        }
        for (int i = 1; i <= m; i++)
            b[i] = lower_bound(v.begin(), v.begin() + sz, b[i]) - v.begin() + 1;
        
        sort(b + 1, b + 1 + m);
        dnq(1, m, 1, n + 1);
        make(1, 1, sz);
        int j = 1;
        for (int i = 1; i <= m; i++) {
            while (j < p[i]) 
                update(1, 1, sz, a[j++], 1);
            inv += 1LL * get(1, 1, sz, b[i] + 1, sz);
        }
        make(1, 1, sz);
        j = n;
        for (int i = m; i > 0; i--) {
            while (j >= p[i])
                update(1, 1, sz, a[j--], 1);
            inv += 1LL * get(1, 1, sz, 1, b[i] - 1);
        }
        cout << inv << endl;
	}
	
	return 0;
}