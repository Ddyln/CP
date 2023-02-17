#include <bits/stdc++.h>
using namespace std;

#define Fname ((string) "test")
#define int long long
#define ii pair <int, int>
#define iii pair <int, ii>
#define fi first
#define se second
#define endl '\n'
const int N = 2e5 + 5;
const int M = 1e9 + 7;

int n, p, p2[44], a[N], fibo[N], sfibo[N], res;
map <int, int> m;
map <int, int> :: iterator it;
vector <int> v;

signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	#ifdef lan_ngu
		freopen((Fname + ".inp").c_str(), "r", stdin);
		freopen((Fname + ".out").c_str(), "w", stdout);
	#endif

	fibo[0] = fibo[1] = 1;
	sfibo[0] = 1;
	sfibo[1] = 2;
	for (int i = 2; i <= 200000; i++) {
		fibo[i] = (fibo[i - 1] + fibo[i - 2]) % M;
		sfibo[i] = (sfibo[i - 1] + fibo[i]) % M;
	}
	// int _nt; cin >> _nt;
	int _nt = 1;
	p2[0] = 1;
	for (int i = 1; i <= 29; i++)
		p2[i] = p2[i - 1] * 2;
	while (_nt--) {
		cin >> n >> p;
		for (int i = 1; i <= n; i++) {
			cin >> a[i];
			m[a[i]]++;
		}
		for (it = m.begin(); it != m.end(); it++) {
			int tmp = it->first;
			bool ok = 1;
			while (tmp) {
				if (tmp % 2 == 1)
					tmp /= 2;
				else if (tmp % 4 == 0)
					tmp /= 4;
				else
					break;
				if (m[tmp]) {
					ok = 0;
					break;
				}
			}
			if (ok)
				v.push_back(it->first);
		}
		for (int x : v) {
			if (p < 30 && p2[p] <= x)
				continue;
			int pos = 0;
			for (int i = 29; i >= 0; i--)
				if (p2[i] <= x) {
					pos = i;
					break;
				}
			(res += sfibo[p - 1 - pos]) %= M;
		}
		cout << res;
	}

	return 0;
}