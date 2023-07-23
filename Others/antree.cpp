#include <bits/stdc++.h>
using namespace std;

#define Fname ((string) "test")
#define int long long
#define ii pair <int, int>
#define iii pair <int, ii>
#define fi first
#define se second
#define endl '\n'
const int N = 1e6 + 4;

int n, k, a[N];

bool check(int r) {
    int i = 1, l = 1, tmp = k;
    while (i <= n && tmp) {
        while (i <= n && a[i] - a[l] <= r)
            i++;
        int p = i - 1;
        tmp--;
        while (i <= n && a[i] - a[p] <= r)
            i++;
        l = i;
    }
    return (i > n);
}

int cnp(int l, int r) {
    if (l == r)
        return l;
    int m = (l + r) / 2;
    if (check(m))
        return cnp(l, m);
    return cnp(m + 1, r);
}

signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	#ifdef lan_ngu
		freopen((Fname + ".inp").c_str(), "r", stdin);
		freopen((Fname + ".out").c_str(), "w", stdout);
	#endif

	int _nt; cin >> _nt;
	while (_nt--) {
        cin >> n >> k;
        for (int i = 1; i <= n; i++)
            cin >> a[i];
        sort(a + 1, a + 1 + n);
        cout << cnp(0, 1e9) << endl;
	}
	
	return 0;
}