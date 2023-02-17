#include <bits/stdc++.h>
using namespace std;

#define Fname ((string) "test")
#define int long long
#define ii pair <int, int>
#define iii pair <int, ii>
#define fi first
#define se second
#define endl '\n'

const int M = 1e9 + 7;

int n, res;
map <ii, int> para;
map <ii, int> :: iterator it;

int C(int n, int k) {
    if (k == 2)
        return n * (n - 1) / 2 % M;
    return n * (n - 1) * (n - 2) / 6 % M;
}

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
        cin >> n;
        for (int i = 1; i <= n; i++) {
            int a, b, c; 
            cin >> a >> b >> c;
            int tmp = __gcd(abs(a), abs(b));
            a /= tmp;
            b /= tmp;
            if (a < 0)
                a *= -1, b *= -1;
            else if (a == 0 && b < 0)
                b *= -1;
            para[{a, b}]++;
        }
        res = C(n, 3);
        for (it = para.begin(); it != para.end(); it++) 
            res = (res - C(it->se, 2) * (n - it->se) % M - C(it->se, 3) + M * 2) % M;
        cout << res;
	}
	
	return 0;
}