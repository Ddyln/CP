#include <bits/stdc++.h>
using namespace std;

#define Fname ((string) "test")
#define int long long
#define ii pair <int, int>
#define iii pair <int, ii>
#define fi first
#define se second
#define endl '\n'

const int N = 5e5 + 2;

int n, m, res, a[N], b[N];

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
        for (int i = 1; i <= n; i++) {
            cin >> a[i];
            b[i] = a[i];
        }
        sort(a + 1, a + 1 + n);

        int sum = 0, p = 1;
        for (; p <= n; p++)
            if (m - (sum + a[p]) >= 0)
                sum += a[p];
            else
                break;
        if (p == 1)
            cout << n + 1 << endl;
        else if (p == n + 1)
            cout << "1\n";
        else 
            cout << n - p + 1 + (sum - a[p - 1] + b[p] > m) << endl;
	}
	
	return 0;
}