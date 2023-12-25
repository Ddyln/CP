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
struct RING {
    int x, y;
    int val;
};

int n, f[N];
RING a[N];

bool cmp(const RING& a, const RING& b) {
    if (a.y != b.y)
        return a.y > b.y;
    else    
        return a.x > b.x;
}
signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	#ifdef lan_ngu
        freopen((Fname + ".inp").c_str(), "r", stdin);
        freopen((Fname + ".ans").c_str(), "w", stdout);
    #endif

	// int _nt; cin >> _nt;
	int _nt = 1;
	while (_nt--) {
        cin >> n;
        for (int i = 1; i <= n; i++) 
            cin >> a[i].x >> a[i].y >> a[i].val;
        sort(a + 1, a + 1 + n, cmp);
        int res = 0;
        for (int i = 1; i <= n; i++) {
            f[i] = a[i].val;
            for (int j = i - 1; j > 0; j--)
                if (a[i].y > a[j].x)
                    f[i] = max(f[i], f[j] + a[i].val);
            res = max(res, f[i]);
            cerr << f[i] << ' ';
        }
        cout << res;
	}
	
	return 0;
}