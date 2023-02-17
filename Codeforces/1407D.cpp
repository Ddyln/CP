#include <bits/stdc++.h>
using namespace std;

#define Fname ((string) "test")
#define ii pair <int, int>
#define iii pair <int, ii>
#define fi first
#define se second
#define endl '\n'
const int N = 3e5 + 5;

int n, a[N], f[N], lmax[N], rmax[N], lmin[N], rmin[N];
deque <int> dq;

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
		cin >> n;
		for (int i = 1; i <= n; i++) {
			cin >> a[i];
			f[i] = n;
		}
		dq.push_front(0);
		for (int i = 1; i <= n; i++) {
			while (dq.size() > 1 && a[dq.back()] <= a[i])
				dq.pop_back();
			lmax[i] = dq.back() + 1;
			dq.push_back(i);
		}
		while (dq.size() > 1)
			dq.pop_back();
		for (int i = 1; i <= n; i++) {
			while (dq.size() > 1 && a[dq.back()] >= a[i])
				dq.pop_back();
			lmin[i] = dq.back() + 1;
			dq.push_back(i);
		}
		while (dq.size())
			dq.pop_back();
		dq.push_back(n + 1);
		for (int i = n; i > 0; i--) {
			while (dq.size() > 1 && a[dq.back()] <= a[i])
				dq.pop_back();
			rmax[i] = dq.back() - 1;
			dq.push_back(i);
		}
		while (dq.size() > 1)
			dq.pop_back();
		for (int i = n; i > 0; i--) {
			while (dq.size() > 1 && a[dq.back()] >= a[i])
				dq.pop_back();
			rmin[i] = dq.back() - 1;
			dq.push_back(i);
		}
		f[0] = n;
		f[1] = 0;
		for (int i = 2; i <= n; i++) {
			f[i] = min(f[i], f[i - 1] + 1);
			f[rmax[i] + 1] = min(f[rmax[i] + 1], f[lmax[i] - 1] + 1);
			f[rmin[i] + 1] = min(f[rmin[i] + 1], f[lmin[i] - 1] + 1);
		}
		cout << f[n];
	}

	return 0;
}