#include <bits/stdc++.h>
using namespace std;

#define Fname ((string) "test")
#define int long long
#define ii pair <int, int>
#define iii pair <int, ii>
#define fi first
#define se second
#define endl '\n'
const int N = 1e5 + 5;

int n, a[N];
set <int> s;
set <int> :: iterator it, it2;

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
		s.clear();
		for (int i = 1; i <= n; i++) {
			it = s.lower_bound(a[i]);
			if (it != s.end()) {
				it2 = it; it2++;
				while (it2 != s.end()) {
					it = s.erase(it);
					it2 = it;
					it2++;
				}
			} else 
				s.insert(a[i]);
		}
		cout << s.size() << endl;
	}

	return 0;
}