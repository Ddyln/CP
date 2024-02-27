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

int n, q, a[N], sum[N];

int get(int l, int r) {
    return sum[r] - sum[l - 1];
}

int cal(int l, int r, int u) {
    if (r > n) return -199218009;
    int x = get(l, r);
    return x * u - x * (x - 1) / 2;
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
        cin >> n;
        for (int i = 1; i <= n; i++) {
            cin >> a[i];
            sum[i] = sum[i - 1] + a[i];
        }
        cin >> q;
        while (q--) {
            int l, u;
            cin >> l >> u;
            int r = n, tmp = l;
            while (l < r) {
                int m = (l + r + 1) / 2;
                if (get(tmp, m) <= u)
                    l = m;
                else
                    r = m - 1;
            }   
            int s = cal(tmp, l, u);
            if (s < cal(tmp, l + 1, u))
                cout << l + 1 << ' ';
            else if (tmp == l)
                cout << l << ' ';
            else if (s == cal(tmp, l - 1, u))
                cout << l - 1 << ' ';
            else
                cout << l << ' ';
        }
        cout << endl;
	}
	
	return 0;
}