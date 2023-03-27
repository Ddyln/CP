#include <bits/stdc++.h>
using namespace std;

#define Fname ((string) "test")
#define int long long
#define ii pair <int, int>
#define iii pair <int, ii>
#define fi first
#define se second
#define endl '\n'
const int N = 2e3 + 3;

int n, m, suf[N], pos[5];
ii a[N], b[N], aNew[5];

istream& operator >> (istream& inDev, ii& a) {
    inDev >> a.fi >> a.se;
    return inDev;
}

bool cmpX(const ii& a, const ii& b) {
    if (a.fi != b.fi)
        return a.fi < b.fi;
    return a.se < b.se;
}

bool cmpY(const ii& a, const ii& b) {
    if (a.se != b.se)
        return a.se < b.se;
    return a.fi < b.fi;
}

bool check(int step) {
    for (int dx = 0; dx <= step; dx++) {
        int dy = step - dx;
        bool ok = 1;
        for (int i = 1; i <= n; i++) {
            int tmp = m + 1;
            for (int j = pos[i]; j <= m; j++) 
                if (a[i].fi + dx <= b[j].fi) {
                    tmp = j;
                    break;
                }
            if (a[i].se + dy <= suf[tmp])
                ok = 0;
        }
        if (ok)
            return 1;
    }
    return 0;
}

int cnp(int l, int r) {
    if (l == r)
        return l;
    int mid = (l + r) / 2;
    if (check(mid))
        return cnp(l, mid);
    return cnp(mid + 1, r);
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
		// Code here
        cin >> n >> m;
        for (int i = 1; i <= n; i++) 
            cin >> a[i];
        // sort(a + 1, a + 1 + n, cmpX);
        // aNew[0] = a[1];
        // sort(a + 1, a + 1 + n, cmpY);
        // aNew[1] = a[1];
        // n = 2 - (aNew[1] == aNew[0]);
        // for (int i = 1; i <= n; i++) {
        //     a[i] = aNew[i - 1];
        //     cout << a[i].fi << ' ' << a[i].se << endl;
        // }
        for (int i = 1; i <= m; i++) 
            cin >> b[i];
        sort(b + 1, b + 1 + m, cmpX);
        suf[m + 1] = -1;
        for (int i = m; i > 0; i--)
            suf[i] = max(b[i].se, suf[i + 1]);
        for (int i = 1; i <= n; i++) {
            pos[i] = m + 1;
            for (int j = 1; j <= m; j++)
                if (b[j].fi >= a[i].fi) {
                    pos[i] = j;
                    break;
                }
        }
        cout << cnp(0, 2e6 + 1);
	}
	
	return 0;
}