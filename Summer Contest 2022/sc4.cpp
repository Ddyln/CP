#include <bits/stdc++.h>
using namespace std;

#define Fname ((string) "sc4")
#define int long long
#define ii pair <int, int>
#define iii pair <int, ii>
#define fi first
#define se second
#define endl '\n'
const int N = 5005;

int n, a[N], f[N][5], res;

signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	freopen((Fname + ".inp").c_str(), "r", stdin);
	freopen((Fname + ".out").c_str(), "w", stdout);

	int _nt; cin >> _nt;
	// int _nt = 1;
	while (_nt--) {
		cin >> n;
		for (int i = 1; i <= n; i++) 
			cin >> a[i];
		res = 0;
		for (int i = 1; i <= n; i++) {
			f[i][1] = 1;
			f[i][2] = f[i][3] = f[i][4] = 0;
			for (int j = i - 1; j > 0; j--)
				if (a[i] > a[j]) {
					f[i][4] += f[j][3];
					f[i][3] += f[j][2];
					f[i][2] += f[j][1];
				}
			res += f[i][4];
		}
		cout << res << endl;
	}

	return 0;
}