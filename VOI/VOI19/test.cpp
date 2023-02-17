#include <bits/stdc++.h>
using namespace std;

#define Fname ((string) "test")
#define int long long
#define ii pair <int, int>
#define iii pair <int, ii>
#define fi first
#define se second
#define endl '\n'
const int N = 100;

string f[N];
int fibo[N];

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
		int n = 3;
		f[1] = "a";
		f[2] = "b";
		fibo[1] = fibo[2] = 1;
		for (; f[n - 1].size() <= 1e5; n++) {
			f[n] = f[n - 1] + f[n - 2];
			fibo[n] = fibo[n - 1] + fibo[n - 2];
		}
		n--;
		cout << f[n].size() << ' ' << fibo[n];
	}

	return 0;
}