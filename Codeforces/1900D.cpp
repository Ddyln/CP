#include <bits/stdc++.h>
using namespace std;

#define Fname ((string) "test")
#define int long long
#define ii pair <int, int>
#define iii pair <int, ii>
#define fi first
#define se second
#define endl '\n'

const int N = 1e5 + 3;

int n, a[N], f[N], cnt[N];

signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	#ifdef lan_ngu
        freopen("test.inp", "r", stdin);
        freopen("test.out", "w", stdout);
    #endif

	int _nt; cin >> _nt;
	// int _nt = 1;
	while (_nt--) {
        cin >> n;
        for (int i = 1; i <= n; i++)
            cin >> a[i];
        sort(a + 1, a + 1 + n);
        memset(cnt, 0, sizeof cnt);
        memset(f, 0, sizeof f);
        for (int i = 1; i <= n; i++) {
            for (int x = 1; x * x <= a[i]; x++)
                if (a[i] % x == 0) {
                    f[x] += cnt[x] * (n - i);
                    cnt[x]++;
                    if (x != a[i] / x) {
                        f[a[i] / x] += cnt[a[i] /x ] * (n - i);
                        cnt[a[i] / x]++;
                    }
                }
        }
        for (int i = 100000; i > 0; i--) {
            for (int j = 2 * i; j <= 100000; j += i)
                f[i] -= f[j];
            f[0] += f[i] * i;
        }
        cout << f[0] << endl;
	}
	
	return 0;
}