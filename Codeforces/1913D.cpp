#include <bits/stdc++.h>
using namespace std;

#define Fname ((string) "test")
#define ll long long
#define ii pair <int, int>
#define iii pair <int, ii>
#define fi first
#define se second
#define endl '\n'
const int INF = 1e9 + 7;
const ll MOD = 998244353;
const int N = 3e5 + 5;

int n, a[N], l[N], r[N], st[4 * N];

void opt(int id) {
    if (a[st[id << 1]] < a[st[(id << 1) + 1]])
        st[id] = st[id << 1];
    else
        st[id] = st[(id << 1) + 1];
}

void Build(int id, int l, int r) {
    if (l == r) {
        st[id] = l;
        return; 
    }
    int m = (l + r) >> 1;
    Build(id << 1, l, m);
    Build((id << 1) + 1, m + 1, r);
    opt(id);
}

int Get(int id, int l, int r, int u, int v) {
    if (r < u || l > v)
        return 0;
    if (l >= u && r <= v)
        return st[id];
    int m = (l + r) >> 1;
    int x = Get(id << 1, l, m, u, v), y = Get((id << 1) + 1, m + 1, r, u, v);
    return (a[x] < a[y] ? x : y);
}

ll cal(int l, int r) {
    // if (l > r) return 0;
    if (l >= r) return 1;
    int pos = Get(1, 1, n, l, r);
    return ((pos - l) + (r - pos) + (pos - l) * (r - pos) % MOD + cal(l, pos - 1) * cal(pos + 1, r) % MOD) % MOD;
}

bool cmp(const ii& a, const ii& b) {
    if (a.fi != b.fi) return a.fi < b.fi;
    return a.se < b.se;
}

signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	#ifdef lan_ngu
        freopen("test.inp", "r", stdin);
        freopen("test.out", "w", stdout);
    #endif

	int _nt; cin >> _nt;
	// int _nt = 1;
	while (_nt--) {
        cin >> n;
        vector <int> v;
        for (int i = 1; i <= n; i++) {
            cin >> a[i];
            v.push_back(a[i]);
        }
        a[0] = INF;
        Build(1, 1, n);
        a[0] = a[n + 1] = -1;
        v.push_back(0);
        for (int i = 1; i <= n; i++) {
            while (a[i] <= a[v.back()]) 
                v.pop_back();
            l[i] = v.back() + 1;
            v.push_back(i);
        }
        v.clear();
        v.push_back(n + 1);
        for (int i = n; i > 0; i--) {
            while (a[i] <= a[v.back()])
                v.pop_back();
            r[i] = v.back() - 1;
            v.push_back(i);
        }
        a[0] = INF;
        ll res = cal(1, n);
        vector <ii> seg;
        for (int i = 1; i <= n; i++) {
            if (i - l[i])
                seg.push_back({l[i], i - 1});
            if (r[i] - i)
                seg.push_back({i + 1, r[i]});
        }
        sort(seg.begin(), seg.end(), cmp);
        int cnt = 0;
        for (int i = 1; i < seg.size(); i++)
            if (seg[i] == seg[i - 1])
                cnt++;
            else {
                res = (res - cnt + MOD) % MOD;
                cnt = 0;
            }
        res = (res - cnt + MOD) % MOD;
        cout << res << endl;
	}
	
	return 0;
}