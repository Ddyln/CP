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

int n, m, res, a[N];

signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	#ifdef lan_ngu
		freopen((Fname + ".inp").c_str(), "r", stdin);
		freopen((Fname + ".out").c_str(), "w", stdout);
	#endif

	int _nt; cin >> _nt;
	// int _nt = 1;
	while (_nt--) {
        cin >> n >> m;
        res = 0;
        for (int i = 1; i <= n; i++) {
            int x;
            cin >> x;
            a[i] = i + x;
        }
        sort(a + 1, a + 1 + n);
        for (int i = 1; i <= n; i++)
            if (m - a[i] < 0)
                break;
            else
                m -= a[i], res++;
        cout << res << endl;
	}
	
	return 0;
}