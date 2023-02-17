#include <bits/stdc++.h>
using namespace std;

#define Fname ((string) "test")
#define int long long
#define ii pair <int, int>
#define iii pair <int, ii>
#define fi first
#define se second
#define endl '\n'
const int N = 3e6 + 5;

int a, b, res;
bool c[N];

signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	#ifdef lan_ngu
		freopen((Fname + ".inp").c_str(), "r", stdin);
		freopen((Fname + ".out").c_str(), "w", stdout);
	#endif

	for (a = 1; a < N; a *= 2)
		c[a] = 1;

	int _nt; cin >> _nt;
	// int _nt = 1;
	while (_nt--) {
		cin >> a >> b;
		res = b - a;
		for (int i = a; i < b; i++)
			res = min(res, i - a + (i | b) + 1 - b);
		for (int i = b + 1; i != b + 1 && !c[i - 1] || i == b + 1; i++) 
			res = min(res, i - b + 1 + (i | a) - i);
		cout << res << endl;		
	}

	return 0;
}