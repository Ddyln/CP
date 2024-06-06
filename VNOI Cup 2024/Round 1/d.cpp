#include <bits/stdc++.h>
using namespace std;

#define Fname ((string) "test")
#define ii pair <int, int>
#define iii pair <int, ii>
#define fi first
#define se second
#define endl '\n'
const int N = 2e5 + 5;

int n;
double x[N], sum[N], res, f[N];

signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	#ifdef lan_ngu
        freopen((Fname + ".inp").c_str(), "r", stdin);
        freopen((Fname + ".out").c_str(), "w", stdout);
    #endif

	int _nt; cin >> _nt;
	// int _nt = 1;
    f[2] = 0.5;
	while (_nt--) {
        cin >> n;
        for (int i = 1; i <= n; i++) {
            cin >> x[i];    
            sum[i] = sum[i - 1] + x[i];
        }
        res = 0;
        for (int i = 2; i <= n; i++) {
            res += f[i] * (x[i] - x[i - 1]);
            x[i] = sum[i] / i;
            f[i + 1] = f[i] * 1.0 / (1 - 1.0 / i);
        }
        cout << fixed << setprecision(7) << res << endl;
	}
	
	return 0;
}