#include <iostream>
using namespace std;

#define Fname ((string) "test")
#define int long long
#define ii pair <int, int>
#define iii pair <int, ii>
#define fi first
#define se second
#define endl '\n'
const int N = 1e6 + 5;

int n, a[N], pre[N], suf[N], res, k;

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
		// Code here
        cin >> n >> k;
        for (int i = 1; i <= n; i++) {
            cin >> a[i];
            pre[i] = pre[i - 1] + a[i];
        }
        for (int i = n; i > 0; i--)
            suf[i] = suf[i + 1] + a[i];
        res = suf[n - k + 1];
        for (int i = 1; i <= k; i++) {
            res = max(res, pre[i] + suf[n - (k - i + 1) + 2]);
        }
        cout << res;
	}
	
	return 0;
}