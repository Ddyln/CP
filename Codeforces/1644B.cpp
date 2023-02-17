#include <bits/stdc++.h>
using namespace std;

#define Fname ((string) "test")
#define int long long
#define ii pair <int, int>
#define iii pair <int, ii>
#define fi first
#define se second
#define endl '\n'

int n, a[55];

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
			a[i] = n - i + 1;
		int cnt = 0;
		do {
			int ok = 1;
			for (int i = 3; i <= n; i++)
				if (a[i] == a[i - 1] + a[i - 2])
					ok = 0;
			if (ok) {
				for (int i = 1; i <= n; i++)
					cout << a[i] << ' ';
				cout << endl;
				cnt++;
			}
			prev_permutation(a + 1, a + 1 + n);
		} while (cnt < n);
	}

	return 0;
}