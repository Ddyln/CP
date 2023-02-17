#include <bits/stdc++.h>
using namespace std;

#define Fname ((string) "test")
#define int long long
#define ii pair <int, int>
#define iii pair <int, ii>
#define fi first
#define se second
#define endl '\n'

int a, b, c, d, cnt[4];
string s;

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
		cin >> a >> b >> c >> d >> s;	
		memset(cnt, 0, sizeof(cnt));
		for (int i = 0; i < s.size(); i++) {
			cnt[s[i] - 'A']++;
			if (i + 1 != s.size() && s[i] != s[i + 1])
				cnt[2 + (s[i] == 'B')]++;
		}
		cout <<  (a + c + d == cnt[0] && cnt[2] >= c && cnt[3] >= d ? "YES\n" : "NO\n");
	}
	
	return 0;
}