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

int n, a[N];

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
        cin >> n;
        int res = 0, m = 1e15, cnt = 0;
        for (int i = 1; i <= n; i++) {
            cin >> a[i];
            res += abs(a[i]);
            if (a[i] < 0)
                cnt++;
            m = min(m, abs(a[i]));
        }
        cout << res - m * (cnt % 2) * 2 << endl;
	}
	
	return 0;
}