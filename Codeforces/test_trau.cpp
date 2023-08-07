#include <bits/stdc++.h>
using namespace std;

#define Fname ((string) "test")
// #define int long long
#define ii pair <int, int>
#define iii pair <int, ii>
#define fi first
#define se second
#define endl '\n'

bool match(string s, string t, int p) {
        for (int i = 0; i < t.size(); i++)
            if (s[i + p] != t[i])
                return 0;
        return 1;
    }

bool wordBreak(string s, vector<string>& wordDict) {
	vector <int> f(s.size() + 1, 0);
	for (int i = 0; i < s.size(); i++)
		if (match(s, wordDict[i], i)) {
			f[i + wordDict[i].size()] |= 1;//(i ? f[i - 1] : true);
		}
	return f[s.size()];
}
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
	return 0;
	string s;
	cin >> s;
	cout << strangePrinter(s);
	
	return 0;
}