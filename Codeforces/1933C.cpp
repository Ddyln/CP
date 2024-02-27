#include <bits/stdc++.h>
using namespace std;

#define Fname ((string) "test")
#define int long long
#define ii pair <int, int>
#define iii pair <int, ii>
#define fi first
#define se second
#define endl '\n'

int cal(int n, int a, int b) {
    if (a < b) swap(a, b);
    int A = 1, B = 1;
    vector <int> v(1, 1);
    while (B * b <= n) v.push_back(B *= b);
    for (; n % A == 0; A *= a) {
        auto it = lower_bound(v.begin(), v.end(), n / A);
        if (it == v.end() || *it != n / A) continue;
        return 1;
    }
    return 0;
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
	while (_nt--) {
        int a, b, l, res = 0;
        cin >> a >> b >> l;
        for (int i = 1; i * i <= l; i++)
            if (l % i == 0) {
                res += cal(l / i, a, b);
                if (i != l / i)
                    res += cal(i, a, b);
            }
        cout << res << endl;
	}
	
	return 0;
}