#include <bits/stdc++.h>
using namespace std;

#define Fname ((string) "test")
#define int long long
#define ii pair <int, int>
#define iii pair <int, ii>
#define fi first
#define se second
#define endl '\n'

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
		string s; cin >> s;
		int cnt[2] = {0, 0};
		for (char c : s)
			cnt[c - '0']++;
		if (cnt[0] == cnt[1])
			cout << cnt[0] - 1 << endl;
		else
			cout << min(cnt[0], cnt[1]) << endl;
	}

	return 0;
}