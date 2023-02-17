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

int n, cnt[N], p2[100], res, s;
map <int, int> m;
deque <int> dq;
deque <int> :: iterator it;

signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	#ifdef lan_ngu
		freopen((Fname + ".inp").c_str(), "r", stdin);
		freopen((Fname + ".out").c_str(), "w", stdout);
	#endif

	p2[0] = 1;
	for (int i = 1; i <= 60; i++)
		p2[i] = p2[i - 1] * 2;

	int _nt; cin >> _nt;
	// int _nt = 1;
	while (_nt--) {
		cin >> n;
		m.clear();
		memset(cnt, 0, sizeof(cnt));
		for (int i = 1; i <= n; i++) {
			int tmp; cin >> tmp;
			m[tmp]++;
		}	
		dq.clear();
		s = 0;
		res = p2[60];	
		for (ii i : m) {
			s += i.second;
			for (int j = 0; j < 35; j++) {
				it = lower_bound(dq.begin(), dq.end(), p2[j], greater <int>());
				int *k2 = lower_bound(p2, p2 + 60, n - s);
				if (it != dq.end()) {
					int *k1 = lower_bound(p2, p2 + 60, s - *it);
					res = min(res, p2[j] - *it + *k1 - s + *it + *k2 - n + s);
				}
				int *k1 = lower_bound(p2, p2 + 60, s);
				res = min(res, *k1 - s + *k2 - n + s + 1);
			}
			dq.push_front(s);
		}
		cout << res << endl;
	}

	return 0;
}