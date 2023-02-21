#include <bits/stdc++.h>
using namespace std;

#define Fname ((string) "test")
#define int long long
#define ii pair <int, int>
#define iii pair <int, ii>
#define fi first
#define se second
#define endl '\n'
const int N = 2e5 + 3;

int n, a[N], q, bit[N];

int Modify(int p, int times) {
    while (times-- && a[p] > 9) {
        int s = 0;
        while (a[p] > 0) {
            s += a[p] % 10;
            a[p] /= 10;
        }
        a[p] = s;
    }
    return a[p];
}

void UpdatePoint(int id, int val) {
    while (id <= n) {
        bit[id] += val;
        id += (id & (-id));
    }
}

void UpdateRange(int l, int r, int val) {
    UpdatePoint(l, val);
    UpdatePoint(r + 1, -val);
}

int Get(int id) {
    int res = 0;
    while (id > 0) {
        res += bit[id];
        id -= (id & (-id));
    }
    return res;
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
        cin >> n >> q;
        for (int i = 1; i <= n; i++)
            cin >> a[i];
        memset(bit, 0, sizeof(bit));
        while (q--) {
            int t = 1;
            cin >> t;
            if (t == 1) {
                int l = 1, r = 1;
                cin >> l >> r;
                UpdateRange(l, r, 1);
            }
            else {
                int x = 0, tmp = 0;
                cin >> x;
                cout << Modify(x, tmp = Get(x)) << endl;
                UpdateRange(x, x, -tmp);
            }
        }
	}
	
	return 0;
}