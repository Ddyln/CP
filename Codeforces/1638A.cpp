#include <bits/stdc++.h>
using namespace std;

#define Fname ((string) "test")
#define int long long
#define ii pair <int, int>
#define iii pair <int, ii>
#define fi first
#define se second
#define endl '\n'
const int N = 505;

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
		for (int i = 1; i <= n; i++)
			if (a[i] != i) {
				for (int j = i + 1; j <= n; j++)
					if (a[j] == i)
						reverse(a + i, a + j + 1);
				break;
			}
		for (int i = 1; i <= n; i++)
			cout << a[i] << ' ';
		cout << endl;
	}

	return 0;
}