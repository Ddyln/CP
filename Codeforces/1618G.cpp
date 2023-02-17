#include <bits/stdc++.h>
using namespace std;

#define Fname ((string) "test")
#define int long long
#define ii pair <int, int>
#define iii pair <int, ii>
#define fi first
#define se second
#define endl '\n'
const int N = 4e5 + 5;

int n, m, q, cur, ans[N], par[N], Rank[N], cnt[N], pre[N], rightmost[N];
ii a[N];
priority_queue <iii, vector <iii>, greater <iii>> upd;
vector <ii> query;

int find(int u) {
	return (par[u] == u ? u : par[u] = find(par[u]));
}

void merge(int u, int v) {
	if (Rank[u] < Rank[v])
		swap(u, v);
	cur -= pre[rightmost[u]] - pre[rightmost[u] - cnt[u]];
	cur -= pre[rightmost[v]] - pre[rightmost[v] - cnt[v]];
	cnt[u] += cnt[v];
	Rank[u] += Rank[v];
	rightmost[u] = max(rightmost[u], rightmost[v]);
	par[v] = u;
	cur += pre[rightmost[u]] - pre[rightmost[u] - cnt[u]];
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
		cin >> n >> m >> q;
		for (int i = 1; i <= n + m; i++) {
			cin >> a[i].fi;
			a[i].se = (i <= n);
			cur += a[i].fi * a[i].se;
			par[i] = i;
			rightmost[i] = i;
			Rank[i] = 1;
		}
		for (int i = 1; i <= q; i++) {
			int k; cin >> k;
			query.push_back({k, q - i});
		}

		sort(a + 1, a + 1 + n + m);
		sort(query.begin(), query.end());

		for (int i = 1; i <= n + m; i++) {
			if (i > 1)
				upd.push({a[i].fi - a[i - 1].fi, {i - 1, i}});
			pre[i] = pre[i - 1] + a[i].fi;
			cnt[i] = a[i].se;
		}

		for (int i = 0; i < q; i++) {
			int id = query[i].se, e = query[i].fi;
			while (upd.size() && upd.top().fi <= e) {
				int u = upd.top().se.fi, v = upd.top().se.se;
				upd.pop();
				u = find(u);
				v = find(v);
				if (u == v)
					continue;
				merge(u, v);
			}
			ans[id] = cur;
		}

		while (q--)
			cout << ans[q] << endl;
	}

	return 0;
}