#include <bits/stdc++.h>
using namespace std;

#define Fname ((string) "io")
#define int long long
#define ii pair <int, int>
#define iii pair <int, ii>
#define fi first
#define se second
#define endl '\n'
const int MASK = (1 << 20) + 5;
const int N = 1005;

int n, m, res;
bool dp[MASK];
string s[N];

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
		for (int i = 1; i <= n; i++) {
			cin >> s[i];
			for (int j = i - 1; j > 0; j--) {
				int tmp = 0;
				for (int k = 0; k < m; k++)
					if (s[i][k] != s[j][k])
						tmp |= (1 << k);
				dp[tmp] = 1;
			}
		}
		for (int i = 0; i <= m; i++)
			for (int mask = 0; mask < (1 << m); mask++)
				if (mask & (1 << i))
					dp[mask] |= dp[mask ^ (1 << i)];
		for (int i = 0; i < (1 << m); i++)
			res += !dp[i];
		cout << res;
	}
	
	return 0;
}