// http://csloj.ddns.net/problem/675
#include <bits/stdc++.h>
using namespace std;

#define Fname ((string) "test")
#define int long long
#define ii pair <int, int>
#define iii pair <int, ii>
#define fi first
#define se second
#define endl '\n'
const int N = 1e5 + 5;

int MOD, x, y, step;
double f[N];

int Pow(int n, int k) {
	if (k < 2)
		return (k ? n : 1);
	int tmp = Pow(n, k / 2);
	tmp = tmp * tmp % MOD;
	return (k % 2 ? tmp * n % MOD : tmp);
}

int C(int n, int k) {
	if (n < k)
		return 0;
    // return (int)round(pow(2, f[n] - f[n - k] - f[k])) % MOD;
    int exp = f[n] - f[n - k] - f[k];
    double res = Pow(2, exp);
    cout << res << ' ';
    res = res * pow(2, f[n] - f[n - k] - f[k] - exp);
    // cout << n << ' ' << k << ' ' << round(res) << ' ' << res << endl;
    cout << exp << endl;
    return (int)round(res) % MOD;
    // // cout <<  << ' ';
    // return round(res);
}

signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	#ifdef lan_ngu
		freopen((Fname + ".inp").c_str(), "r", stdin);
		freopen((Fname + ".out").c_str(), "w", stdout);
	#endif

	int _nt; cin >> _nt;
	// int _nt = 1;
    f[0] = 0;
    for (int i = 1; i <= 100000; i++)
        f[i] = f[i - 1] + log2(i);
	while (_nt--) {
        cin >> step >> x >> y >> MOD;
        x = abs(x);
        y = abs(y);
        int tmp = MOD;
        MOD = 1e9 + 7;
        cout << C(10, 3);
        return 0;
        if (x + y > step || (step - (x + y)) % 2 == 1) {
            cout << "0\n";
            continue;
        }
        int res = 0, other = step - x - y;
        for (int hori = 0, verti = other / 2; verti >= 0; hori++, verti--) {
            int tmp = C(step, x + hori);
            tmp = tmp * C(step - x - hori, hori) % MOD;
            tmp = tmp * C(step - x - hori * 2, verti) % MOD;
            res = (res + tmp) % MOD;
        }
        cout << res % tmp << endl;
	}
	
	return 0;
}