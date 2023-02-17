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

int n, a[N];
vector <int> v[N], b;

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
		for (int i = 0; i <= n; i++)
			v[i].clear();
		for (int i = 1; i <= n; i++) {
			cin >> a[i];
			v[a[i]].push_back(i);
		}
		for (int i = 0; i <= n; i++)
			reverse(v[i].begin(), v[i].end());
		b.clear();
		for (int i = 1, mex = 0; i <= n;) {
			if (v[mex].empty()) {
				b.push_back(mex);
				for (int j = 0; j < mex; j++)
					while (v[j].size() && v[j].back() <= i)
						v[j].pop_back();
				i++;
				mex = 0;
			} else 
				i = max(i, v[mex++].back());
		}
		cout << b.size() << endl;
		for (int x : b)
			cout << x << ' ';
		cout << endl;
	}

	return 0;
}