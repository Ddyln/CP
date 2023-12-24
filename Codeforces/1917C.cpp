#include <bits/stdc++.h>
using namespace std;

#define Fname ((string) "test")
#define ii pair <int, int>
#define iii pair <int, ii>
#define fi first
#define se second
#define endl '\n'

const int N = 1e5 + 5;

int n, m, d, a[2003], b[N], tmp[2003];

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
        cin >> n >> m >> d;
        for (int i = 1; i <= n; i++)
            cin >> a[i];
        for (int i = 1; i <= m; i++)
            cin >> b[i];
        int res = 0;
        for (int i = 0; i < min({n * 2, m, d}); i++) {
            memset(tmp, 0, sizeof tmp);
            for (int j = 1; j <= i; j++)
                tmp[1]++, tmp[b[j] + 1]--;
            for (int j = 1; j <= n; j++)
                tmp[j] += tmp[j - 1];
            int cnt = 0;
            for (int j = 1; j <= n; j++)
                if (a[j] + tmp[j] == j)
                    cnt++;
            res = max(res, cnt + (d - i - 1) / 2);
        }
        cout << res << endl;
	}
	
	return 0;
}