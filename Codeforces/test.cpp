#include <bits/stdc++.h>
using namespace std;

#define Fname ((string) "test")
// #define int long long
#define ii pair <int, int>
#define iii pair <int, ii>
#define fi first
#define se second
#define endl '\n'

int f[100][100][256];

int solve(int l, int r, int ch, string& s) {
    if (l == r)
        return !(s[l] == ch);
    if (f[l][r][ch])
        return f[l][r][ch];
    return f[l][r][ch] = min(solve(l + 1, r, s[l], s) + !(s[l] == ch), solve(l, r - 1, s[r], s) + !(s[r] == ch));
}

int strangePrinter(string s) {
    int n = s.size();
    return solve(0, n - 1, 0, s);
}

signed main() {
    ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	#ifdef lan_ngu
		freopen((Fname + ".inp").c_str(), "r", stdin);
		freopen((Fname + ".out").c_str(), "w", stdout);
	#endif
    string s;
	cin >> s;
	cout << strangePrinter(s);
    return 0;
}