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
		int ok = 1;
		for (int i = 0; i < s.size() - 1; i++)
			for (int j = i + 1; j < s.size(); j++)
				if ((s[i] == 'R' && s[j] == 'r') || (s[i] == 'G' && s[j] == 'g') || (s[i] == 'B' && s[j] == 'b'))
					ok = 0;
		cout << (ok ? "YES\n" : "NO\n");
	}

	return 0;
}