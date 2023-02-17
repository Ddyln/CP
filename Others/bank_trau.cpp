#include <bits/stdc++.h>
using namespace std;

#define Fname ((string) "test")
#define int long long
#define ii pair <int, int>
#define iii pair <int, ii>
#define fi first
#define se second
#define endl '\n'

const int N = 9e4 + 4;

int n, q, a[N], res, budget, sum, len, resLen, resMin;

void Try(int i) {
	if (i > n) {
		if ((len > resLen || (len == resLen && res > resMin)) && sum <= budget)
			resLen = len, resMin = res;
	} else {
		Try(i + 1);
		sum += a[i];
		len++;
		int tmp = res;
		res = min(res, a[i]);
		Try(i + 1);
		res = tmp;
		len--;
		sum -= a[i];
	}
}

signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	#ifdef lan_ngu
		freopen((Fname + ".inp").c_str(), "r", stdin);
		freopen((Fname + ".ans").c_str(), "w", stdout);
	#endif

	// int _nt; cin >> _nt;
	int _nt = 1;
	while (_nt--) {
		cin >> n >> q;
		for (int i = 1; i <= n; i++)
			cin >> a[i];
		while (q--) {
			cin >> budget;
			res = 1e9;
			Try(1);
			if (resLen == 0)
				cout << "0\n";
			else
				cout << resLen << ' ' << resMin << endl;
		}
	}
	
	return 0;
}