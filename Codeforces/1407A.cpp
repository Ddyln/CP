#include <bits/stdc++.h>
using namespace std;

#define Fname ((string) "test")
#define int long long
#define ii pair <int, int>
#define iii pair <int, ii>
#define fi first
#define se second
#define endl '\n'

int n, cnt[2];

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
		cnt[0] = cnt[1] = 0;
		for (int i = 1; i <= n; i++) {
			int a; cin >> a;
			cnt[a]++;
		}
		for (int val = 0; val < 2; val++)
			if (cnt[val] >= n / 2) {
				if (val == 1 && cnt[1] % 2 == 1)
					cnt[1]--;
				cout << cnt[val] << endl;
				for (int i = 1; i <= cnt[val]; i++)
					cout << val << ' ';
				cout << endl;
				break;
			}
	}

	return 0;
}