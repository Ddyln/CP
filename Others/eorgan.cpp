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

int n, a[N], inAr[N], res;

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
            cin >> a[i];
            inAr[a[i]]++;
        }
        res = n;
        for (int i = 2; i <= N - 5; i++) {
            int tmp = 0;
            for (int j = i; j <= N - 5; j += i) 
                tmp += inAr[j];
            res = max(res, tmp * i * (tmp > 1));
        }
        cout << res;
	}
	return 0;
}