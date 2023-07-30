#include <bits/stdc++.h>
using namespace std;

#define Fname ((string) "test")
// #define int long long
#define ii pair <int, int>
#define iii pair <int, ii>
#define fi first
#define se second
#define endl '\n'

int strangePrinter(string s) {
	int n = s.size();
	vector<vector<int>> dp(n, vector<int>(n, 0));
	
	for (int i = n-1; i >= 0; --i) {
		dp[i][i] = 1;
		for (int j = i+1; j < n; ++j) {
			dp[i][j] = dp[i][j-1] + 1;
			for (int k = i; k < j; ++k) {
				if (s[k] == s[j]) {
					dp[i][j] = min(dp[i][j], dp[i][k] + (k+1<=j-1 ? dp[k+1][j-1] : 0));
				}
			}
		}
	}
	return dp[0][n-1];
}

signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	#ifdef lan_ngu
		freopen((Fname + ".inp").c_str(), "r", stdin);
		freopen((Fname + ".ans").c_str(), "w", stdout);
	#endif

	string s;
	cin >> s;
	cout << strangePrinter(s);
	
	return 0;
}