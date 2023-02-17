#include <bits/stdc++.h>
using namespace std;

#define Fname ((string) "test")
#define int long long
#define ii pair <int, int>
#define iii pair <int, ii>
#define fi first
#define se second
#define endl '\n'
const int maxn = 1e4 + 5;
const int maxm = 1e5 + 5;

int n, m, a[maxn], f[maxm], res, M, num[105];
string str;
set <int> s;
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
		cin >> n >> m;
		for (int i = 1; i <= n; i++) 
			cin >> a[i];
		sort(a + 1, a + 1 + n, greater <int>());
		cin >> str;
		str += '0';
		m++;
		for (int j = 1; j <= n; j++) {
			if (a[j] == a[j - 1])
				continue;
			dq.clear();
			dq.push_back(0);
			for (int i = 1; i <= m; i++) {
				if (str[i - 1] == '1')
					continue;
				while (i - dq.front() > a[j])
					dq.pop_front();
				f[i] = f[dq.front()] + 1;
				while (dq.size() && f[dq.back()] > f[i])
					dq.pop_back();
				dq.push_back(i);
			}
			num[a[j]] = f[m];
		}
		f[1] = a[1] = num[a[1]];
		f[2] = a[2] = num[a[2]];
		for (int i = 3; i <= n; i++) {
			a[i] = num[a[i]];
			f[i] = a[i] + a[1] + f[i - 1];
			if (i > 3)
				f[i] = min(f[i], a[2] + a[1] + a[i] + a[2] + f[i - 2]);
		}
		cout << f[n];
	}

	return 0;
}