#include <bits/stdc++.h>
using namespace std;

#define Fname ((string) "test")
#define int long long
#define ii pair <int, int>
#define iii pair <int, ii>
#define fi first
#define se second
#define endl '\n'
const int M = 998244353;
const int N = 2e5 + 5;

int n, m, k, q;
map <ii, int> mp;
map <ii, int> :: iterator it;
vector <iii> v;
set <int> row, col;

int Pow(int n, int k) {
	if (k < 2)
		return (k == 1 ? n : 1);
	int tmp = Pow(n, k / 2);
	(tmp *= tmp) %= M;
	return (k & 1 ? tmp * n % M : tmp);
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
		cin >> n >> m >> k >> q;
		mp.clear();
		for (int i = 1; i <= q; i++) {
			int x, y; cin >> x >> y;
			mp[{x, y}] = i;
		}
		v.clear();
		for (it = mp.begin(); it != mp.end(); it++)
			v.push_back({it->se, it->fi});
		sort(v.begin(), v.end(), greater <iii>());
		int cnt = 0;
		row.clear();
		col.clear();
		for (int i = 0; i < v.size(); i++) {
			int x = v[i].se.fi, y = v[i].se.se, ok = 1;
			if (row.find(x) != row.end() && col.find(y) != col.end())
				ok = 0;
			cnt += ok;
			col.insert(y);
			row.insert(x);
			if (col.size() == m || row.size() == n) 
				break;
		}
		cout << Pow(k, cnt) << endl;
	}

	return 0;
}