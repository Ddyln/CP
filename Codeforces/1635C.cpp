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
		if (a[n] < 0 && a[n - 1] < 0) {
			bool res = 1;
			for (int i = 2; res && i <= n; i++)
				if (a[i] < a[i - 1])
					res = 0;
			cout << (res ? "0\n" : "-1\n");
		} else if (a[n - 1] > a[n])
			cout << "-1\n";
		else { 
			cout << n - 2 << endl;
			for (int i = 1; i <= n - 2; i++)
				cout << i << ' ' << n - 1 << ' ' << n << endl;
			cout << endl;
		}
	}

	return 0;
}