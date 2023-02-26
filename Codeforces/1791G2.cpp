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

int n, m, res, a[N], suf[N], st[4 * N];
vector <int> v;
map <int, int> id, cnt;

struct FENWICK {
    int bit[N];

    void Update(int id, int val) {
        while (id <= n) {
            bit[id] += val;
            id += (id & (-id));
        }
    }

    int Get(int id) {
        int res = 0;
        while (id > 0) {
            res += bit[id];
            id -= (id & (-id));
        }
        return res;
    }
} f;

int cnp(int l, int r) {
    if (l == r)
        return l;
    int mid = (l + r) / 2;
    if (m - suf[mid] < 0)
        return cnp(mid + 1, r);
    return cnp(l, mid);
}

void Update(int id, int l, int r, int p, int val) {
    if (r < p || l > p)
        return;
    if (l == r)
        return void(st[id] = val);
    int mid = (l + r) / 2;
    Update(id * 2, l, mid, p, val);
    Update(id * 2 + 1, mid + 1, r, p, val);
    st[id] = st[id * 2] + st[id * 2 + 1];
}

int Walk(int id, int l, int r, int lim) {
    if (l == r) {
        return (st[id] <= lim ? l : 0);
    }
    int mid = (l + r) / 2;
    if (st[id * 2] > lim)
        return Walk(id * 2, l, mid, lim);
    return max(mid, Walk(id * 2 + 1, mid + 1, r, lim - st[id * 2]));
}

int Get(int id, int l, int r, int p) {
    if (l > p || r < p)
        return 0;
    if (l == r)
        return st[id];
    int mid = (l + r) / 2;
    return Get(id * 2, l, mid, p) + Get(id * 2 + 1, mid + 1, r, p);
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
        res = 0;
        v.clear();
        id.clear();
        cnt.clear();
        memset(st, 0, sizeof(st));
        memset(f.bit, 0, sizeof(f.bit));
        for (int i = 1; i <= n; i++) {
            cin >> a[i];
            if (i <= n / 2)
                a[i] += i;
            else
                v.push_back(a[i]);
        }
        sort(a + 1, a + n / 2 + 1);
        sort(v.begin(), v.end());
        int l = v.size();
        for (int i = 0; i < l; i++)
            if (i == 0 || v[i] != v[i - 1])
                id[v[i]] = i + 1;
        for (int i = n; i > n / 2; i--) {
            if (m - (i + a[i]) >= 0) {
                int p = Walk(1, 1, l, m - (i + a[i]));
                res = max(res, 1 + f.Get(p));
            }
            f.Update(id[a[i]] + cnt[a[i]], 1);
            Update(1, 1, l, id[a[i]] + cnt[a[i]], a[i] + n + 1 - i);
            cnt[a[i]]++;
        }

        for (int i = n; i > n / 2; i--)
            a[i] += n + 1 - i;
        sort(a + n / 2  + 1, a + n + 1, greater <int>());
        suf[n + 1] = 0;
        for (int i = n; i > n / 2; i--) 
            suf[i] = suf[i + 1] + a[i];
        for (int i = 1; i <= n / 2; i++) {
            if (m - a[i] < 0)
                break;
            m -= a[i];
            int p = cnp(n / 2 + 1, n + 1);
            res = max(res, i + n + 1 - p);
        }
        cout << res << endl;
	}
	
	return 0;
}