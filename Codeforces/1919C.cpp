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
const int INF = 1e9;

int n, a[N], f[N], pre[N], lds[N], maxL[N];
bool check[N];

int cnp(int l, int r, int val) {
    if (l == r)
        return l;
    int m = (l + r) >> 1;
    if (f[m] >= val)
        return cnp(m + 1, r, val);
    else
        return cnp(l, m, val);
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
            f[i] = check[i] = 0;
        }
        f[0] = INF;
        int res = 0;
        for (int i = 1; i <= n; i++) {
            int k = cnp(0, n, a[i]);
            pre[i] = f[k - 1];
            f[k] = a[i];
            lds[i] = k;
            res = max(res, k);
        }
        int pos = n;
        maxL[1] = lds[1];
        for (int i = 2; i <= n; i++)
            maxL[i] = max(maxL[i - 1], lds[i]);
        for (; pos > 0; pos--) {
            if (res == 1) break;
            if (maxL[pos - 1] != res) {
                check[pos] = 1;
                res--;
            }
        }
        int k = 1;
        for (int i = 2; i <= pos; i++)
            if (a[k] < a[i]) k = i;
        check[k] = 1;
        int x = INF;
        res = 0;
        for (int i = 1; i <= n; i++)
            if (!check[i]) {
                res += (x < a[i]);
                x = a[i];
            }
            else cerr << a[i] << ' ';
        cout << res << endl;
	}
	
	return 0;
}