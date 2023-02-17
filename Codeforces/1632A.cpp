#include <bits/stdc++.h>
using namespace std;

#define Fname ((string) "test")
#define int long long
#define ii pair <int, int>
#define iii pair <int, ii>
#define fi first
#define se second
#define endl '\n'

int n;
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
		cin >> n >> s;
		if (n > 2)	
			cout << "NO\n";
		else if (n == 1)
			cout << "YES\n";
		else
			cout << (s[0] != s[1] ? "YES\n" : "NO\n");
	}

	return 0;
}