#include <bits/stdc++.h>
using namespace std;

#define Fname ((string) "test")
// #define int long long
#define ii pair <int, int>
#define iii pair <int, ii>
#define fi first
#define se second
#define endl '\n'
const int N = 2e5 + 5;
const int BL = sqrt(N) + 5;

int n, m, b[BL][BL], x[N], y[N], a[N], last[N], block;

void update(int day, int k, int val) {
	int T = x[k] + y[k];
	int l = (day + x[k]) % T, r = (day + T - 1) % T;
	if (l <= r) 
		for (int i = l; i <= r; i++)
			b[T][i] += val;
	else {
		for (int i = l; i < T; i++)
			b[T][i] += val;
		for (int i = 0; i <= r; i++)
			b[T][i] += val;
	}
}

int get(int day) {
	int res = 0;
	for (int i = 2; i <= block; i++)
		res += b[i][day % i];
	return res;
}

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
		cin >> n >> m;
		block = sqrt(m);
		for (int i = 1; i <= n; i++) 
			cin >> x[i] >> y[i];
		for (int i = 1; i <= m; i++) {
			int t, k; cin >> t >> k;
			if (t == 1) {
				if (x[k] + y[k] >= block) {
					for (long long j = i + x[k]; j <= m; j += x[k] + y[k]) {
						a[j]++;
						if (j + y[k] <= m)
							a[j + y[k]]--; 
					}
				} else 
					update(i, k, 1);
				last[k] = i;
			} else {
				if (x[k] + y[k] >= block) {
					bool ok = 1;
					for (long long j = last[k] + x[k]; j <= m || ok; j += x[k] + y[k]) {
						if (j >= i) {
							if (ok) {
								ok = 0;
								if (j - x[k] > i) {
									a[i]--;
									if (j - x[k] <= m)
										a[j - x[k]]++;
								}
								if (j > m)
									break;
							} 
							a[j]--;
							if (j + y[k] <= m)
								a[j + y[k]]++;
						}
					}
				} else 
					update(last[k], k, -1);
			}
			cout << get(i) + (a[i] += a[i - 1]) << endl;
		}
	}

	return 0;
}