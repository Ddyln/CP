#include <bits/stdc++.h>
using namespace std;

#define Fname ((string) "test")
#define ii pair <int, int>
#define iii pair <int, ii>
#define fi first
#define se second
#define endl '\n'
const int N = 2e5 + 5;
const int A = 1e6 + 5;

struct QUERY{
	int id, fi, se;
};

int n, q, a[N], cnt[A], s;
long long res, ans[N];
vector <QUERY> query;

bool cmp(const QUERY &a, const QUERY &b) {
	if (a.fi / s != b.fi / s)
		return (a.fi / s < b.fi / s);
	return a.se < b.se;
}

void add(int x) {
	res -= 1LL * x * cnt[x] * cnt[x];
	cnt[x]++;
	res += 1LL * x * cnt[x] * cnt[x];
}

void rmv(int x) {
	res -= 1LL * x * cnt[x] * cnt[x];
	cnt[x]--;
	res += 1LL * x * cnt[x] * cnt[x];
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
		s = sqrt(n);
		for (int i = 1; i <= n; i++)
			cin >> a[i];
		for (int i = 1; i <= q; i++) {
			int l, r; cin >> l >> r;
			query.push_back({q - i, l, r});
		}	
		sort(query.begin(), query.end(), cmp);
		int l = 0, r = 0;
		for (int i = 0; i < q; i++) {
			while (r < query[i].se)
				add(a[++r]);
			while (r > query[i].se)
				rmv(a[r--]);
			while (l < query[i].fi)
				rmv(a[l++]);
			while (l > query[i].fi)
				add(a[--l]);
			ans[query[i].id] = res;
		}
		while (q--)
			cout << ans[q] << endl;
	}
	
	return 0;
}