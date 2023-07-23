#include <bits/stdc++.h>
using namespace std;

#define Fname ((string) "test")
#define int long long
#define ii pair <int, int>
#define iii pair <int, ii>
#define fi first
#define se second
#define endl '\n'
const int N = 20;

int n, m, a[N], res;

double Diff(double x) {
    double res = 0;
    for (int i = 0; i < n; i++)
        res += 2 * (x - a[i]);
    return res; 
}

double cnp(double l, double r, int turn) {
    if (!turn)
        return (r + l) / 2;
    double mid = (l + r) / 2;
    double d = Diff(mid);
    if (d == 0)
        return mid;
    return (d > 0 ? cnp(l, mid, turn - 1) : cnp(mid, r, turn - 1));
}

bool check() {
    double m1 = 0;
    if (n % 2 == 1) 
        m1 = a[n / 2];
    else
        m1 = (a[n / 2 - 1] + a[n / 2]) / 2.0;
    double m2 = cnp(a[0], a[n - 1], 64);
    return m1 == m2;
}

void Try(int i, int val) {  
    if (i == n) {
        if (check()) {
            res++;
            for (int i = 0; i < n; i++)
                cout << a[i] << ' ';
            cout << endl;
        }
    }
    else {
        for (int j = val; j <= m; j++) {
            a[i] = j;
            Try(i + 1, j);
        }
    }
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
        cin >> n >> m;
        Try(0, 1);
        cout << res;
	}
	
	return 0;
}