#include <bits/stdc++.h>
using namespace std;

#define Fname ((string) "test")
#define int long long
#define ii pair <int, int>
#define iii pair <int, ii>
#define fi first
#define se second
#define endl '\n'

const int INF = 1e16;
const int N = 3e5 + 4;

struct SegmentTree {
	int n = 0, *st = NULL, *lazy = NULL;

private:
	void down(int id, int l, int r) {
		if (lazy[id]) {
			int m = (l + r) >> 1;
			st[id << 1] += lazy[id];
			st[(id << 1) + 1] += lazy[id];
			lazy[id << 1] += lazy[id];
			lazy[(id << 1) + 1] += lazy[id];
		}
		lazy[id] = 0;
	}

	void update(int id, int l, int r, int u, int v, int val) {
		if (r < u || l > v)
			return;
		if (l >= u && r <= v) {
			st[id] += val;
			lazy[id] += val;
			return;
		}
		int m = (l + r) >> 1;
		down(id, l, r);
		update(id << 1, l, m, u, v, val);
		update((id << 1) + 1, m + 1, r, u, v, val);
		st[id] = min(st[id << 1], st[(id << 1) + 1]);
	}

	int get(int id, int l, int r, int u, int v) {
		if (r < u || l > v)
			return INF;
		if (l >= u && r <= v)
			return st[id];
		int m = (l + r) >> 1;
		return min(get(id << 1, l, m, u, v), get((id << 1) + 1, m + 1, r, u, v));
	}
public:
	SegmentTree(int _n) {
		st = new int[4 * n + 3];
		lazy = new int[4 * n + 3];
		n = _n;
	} 

	~SegmentTree() {
		delete[] st;
		delete[] lazy;
	}

	void update(int l, int r, int val) {
		update(1, 1, n, l, r, val);
	}

	int get(int l, int r) {
		return get(1, 1, n, l, r);
	}
};

int n, a[N], f[N], r[N], l[N];

int GetF(int l, int r) {
	if (l > r) return 0;
	return pf[r] - pf[l - 1];
}

void AddF(int l, int r) {
	if (l > r) return;
	f[l]
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
		cin >> n;
		for (int i = 1; i <= n; i++) 
			cin >> a[i];
		vector <int> v;
		a[0] = a[n + 1] = -1;
		v.push_back(0);
		for (int i = 1; i <= n; i++) {
			while (a[i] <= a[v.back()]) v.pop_back();
			l[i] = v.back() + 1;
			v.push_back(i);
		}
		v.clear();
		v.push_back(n + 1);
		for (int i = n; i > 0; i--) {
			while (a[i] <= a[v.back()]) v.pop_back();
			r[i] = v.back() - 1;
			v.push_back(i);
		}
		memset(f, 0, sizeof f);
		f[0] = 1;
		// int res = 0;
		// for (int i = 1; i <= n; i++) {
		// 	f[i] = f[i - 1];
		// 	for (int j = i - 2; j >= 0; j--)
		// 		if (r[j] >= i - 1 || l[i] <= j + 1)
		// 			f[i] += f[j];
		// 	if (r[i] == n)
		// 		res += f[i];
		// }
		for (int i = 1; i <= n; i++) {
			f[i] = f[i - 1] + GetF(l[i] - 1, i - 2);
			AddF(i + 2, r[i] + 1, f[i]);
			pf[i] = pf[i - 1] + f[i];
		}
		cout << res << endl;
	}
	
	return 0;
}