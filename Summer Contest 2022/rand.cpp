#include <bits/stdc++.h>
using namespace std;

#define Fname ((string) "sc5")
#define int long long
#define ii pair <int, int>
#define iii pair <int, ii>
#define fi first
#define se second
#define endl '\n'

signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	// freopen((Fname + ".inp").c_str(), "r", stdin);
	freopen((Fname + ".inp").c_str(), "w", stdout);

	// int _nt; cin >> _nt;
	int _nt = 20;
	cout << _nt << endl;
	_nt = 0;
	for (int i = 1; i <= 20; i++)
		cout << "10 10 " << "20 " << i << endl;
	while (_nt--) {
		int n = rand() % 15 + 1;
		int m = 100 / n;
		int c = rand() % 20 + 1;
		int k = rand() % 20 + 1;
		cout << n << ' ' << m << ' ' << c << ' ' << k << endl;
	}

	return 0;
}