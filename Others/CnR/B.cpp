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
const int MOD = 1e9 + 7;

int n, q, a, lazy[4 * N], s;

void Down(int id) {
    lazy[id * 2] += lazy[id];
    lazy[id * 2 + 1] += lazy[id];
    lazy[id] = 0;
}

void Update(int id, int l, int r, int u, int v, int val) {
    if (r < u || l > v)
        return;
    if (l >= u && r <= v) {
        lazy[id] += val;
        return;
    }
    Down(id);
    int m = (l + r) / 2;
    Update(id * 2, l, m, u, v, val);
    Update(id * 2 + 1, m + 1, r, u, v, val);
}

int Get(int id, int l, int r, int p) {  
    if (r < p || l > p)
        return 0;
    if (l == r)
        return lazy[id];
    Down(id);
    int m = (l + r) / 2;
    return Get(id * 2, l, m, p) + Get(id * 2 + 1, m + 1, r, p);
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
		cin >> n >> q >> a;
        a = a * a % MOD;
        while (q--) {
            int t, l, r;
            cin >> t >> l >> r;
            if (t == 1) {
                cin >> s;
                Update(1, 1, n, l, r, 1);
            }
            else {
                int tmp = Get(1, 1, n, l);
                cout << ((l - 1) * (l - 1) % MOD + a) % MOD * tmp % MOD << endl;
                Update(1, 1, n, l, l, -tmp);
            }
        }
	}
	
	return 0;
}