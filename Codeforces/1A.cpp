#include <bits/stdc++.h>
using namespace std;

#define Fname ((string) "test")
#define int long long
#define ii pair<int, int>
#define iii pair<int, ii>
#define fi first
#define se second
#define endl '\n'

signed main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
#ifdef lan_ngu
	freopen((Fname + ".inp").c_str(), "r", stdin);
	freopen((Fname + ".out").c_str(), "w", stdout);
#endif

	// int _nt; cin >> _nt;
	int _nt = 1, n, m, a;
	while (_nt--)
	{
		cin >> n >> m >> a;
		cout << ((n - 1) / a + 1) * ((m - 1) / a + 1);
	}

	return 0;
}