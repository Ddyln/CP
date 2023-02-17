#include <bits/stdc++.h>
using namespace std;

#define Fname ((string) "test")
#define int long long
#define ii pair <int, int>
#define iii pair <int, ii>
#define fi first
#define se second
#define endl '\n'
const int N = 3e5 + 5;

int n, m, a[N], nst, H[105][105], f[105];
string s[N];
bool can[105][105];
vector <int> adj[100005];
vector <int> :: iterator it;
map <string, int> mp, dp;

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
		if (n <= 100) {
			for (int i = 1; i <= n; i++) {
				string tmp = "";
				cin >> s[i] >> a[i];
				f[i] = a[i];
				for (int j = 0; j < s[i].size(); j++) {
					tmp += s[i][j];
					if (!mp[tmp])
						mp[tmp] = ++nst;
					H[i][j + 1] = mp[tmp];
				}
			}
			for (int i = 1; i < n; i++)
				for (int j = i + 1; j <= n; j++)
					if (s[i].size() >= s[j].size())
						can[i][j] = (H[i][s[j].size()] == H[j][s[j].size()]);
			for (int i = 1; i <= m; i++) {
				int x, y; cin >> x >> y;
				adj[x].push_back(y);
				adj[y].push_back(x);
			}
			for (int i = 1; i <= 100000; i++)
				sort(adj[i].begin(), adj[i].end());
			for (int i = 1; i < n; i++)
				for (int j = i + 1; j <= n; j++)
					if (can[i][j])
						f[j] = max(f[j], f[i] + a[j]);
					else {
						it = lower_bound(adj[a[i]].begin(), adj[a[i]].end(), a[j]);
						if (it != adj[a[i]].end() && *it == a[j])
							f[j] = max(f[j], f[i] + a[j]);
					}
			int res = 0;
			for (int i = 1; i <= n; i++) {
				// cerr << f[i] << ' ';
				res = max(res, f[i]);
			}
			cout << res;
		} else {
			for (int i = n; i > 0; i--) {
				cin >> s[i] >> a[i];
				// dp[s[i]] = a[i];
			}
			for (int i = 1; i <= m; i++) {
				int x, y;
				cin >> x >> y;
			}
			int res = 0;
			for (int i = 1; i <= n; i++) {
				string tmp = "";
				dp[s[i]] = max(dp[s[i]], a[i]);
				for (int j = 0; j < s[i].size() - 1; j++) {
					tmp += s[i][j];
					if (dp[tmp])
						dp[s[i]] = max(dp[s[i]], dp[tmp] + a[i]);
				}
				// cerr << dp[s[i]] << ' ';
				res = max(res, dp[s[i]]);
			}
			cout << res;
		}
	}	

	return 0;
}