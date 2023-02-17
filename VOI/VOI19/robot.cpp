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

int n, cur, res;
char a[5][N];

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
		for (int i = 1; i <= 3; i++)
			for (int j = 1; j <= n; j++)
				cin >> a[i][j];
		for (int i = 1; i <= n; i++) {
			if (a[1][i] == '#')
				cur = 0;
			else if (a[1][i] == 'S')
				cur |= 1;
			else if (a[1][i] == 'T')
				cur |= 2;
			if (cur == 3) {
				res++;
				cur = 0;
			}
		}
		cout << res;
	}

	return 0;
}