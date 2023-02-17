#include <bits/stdc++.h>
using namespace std;

#define Fname ((string) "test")
#define ii pair <int, int>
#define iii pair <int, ii>
#define fi first
#define se second
#define endl '\n'
const int N = 1e6 + 5;
const int maxA = 42e5;

int n, p2[30], f[maxA];
unsigned int a[N];

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
		p2[0] = 1;
		for (int i = 1; i <= 22; i++)
			p2[i] = p2[i - 1] * 2;
		memset(f, -1, sizeof(f));
		for (int i = 1; i <= n; i++) {
			cin >> a[i];		
			f[a[i]] = a[i];
		}
		for (int i = 0; i < 22; i++)
			for (int mask = 0; mask < maxA; mask++)
				if (mask & p2[i])
					f[mask] = max(f[mask ^ p2[i]], f[mask]);
		for (int i = 1; i <= n; i++) 
			cout << f[((~a[i]) << 10) >> 10] << ' ';
	}

	return 0;
}