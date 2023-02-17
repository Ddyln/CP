#include <bits/stdc++.h>
using namespace std;

#define int long long

int d, n, ans;

signed main() {
	ios_base::sync_with_stdio(false); 
	cin.tie(NULL);
	#ifdef lan_ngu
		freopen("test.inp", "r", stdin);
		freopen("test.out", "w", stdout);
	#endif
	cin >> n;
	int d = sqrt(n);
	while (n) {
		if (n % 2 == 0) {
			ans += n / 2;
			break;
		}
		bool ok = 1;
		for (int i = 2; i <= d; i++)
			if (n % i == 0) {
				d = i;
				n -= i;
				ok = 0; 
				break;
			}
		ans++;
		n -= n * ok;
	}
	cout << ans;
	return 0;
}