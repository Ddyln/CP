#include <bits/stdc++.h>
using namespace std;

#define Fname ((string) "test")
#define int long long
#define ii pair <int, int>
#define iii pair <int, ii>
#define fi first
#define se second
#define endl '\n'
const int N = 105;


int n, m, a[N][N], s[N][N], res = 1e7, p, q;

int Get(int i1, int j1, int i2, int j2) {
    return s[i2][j2] - s[i2][j1 - 1] - s[i1 - 1][j2] + s[i1 - 1][j1 - 1];
}

int Area(int i1, int j1, int i2, int j2) {
    return (i2 - i1 + 1) * (j2 - j1 + 1);
}

void Optimize(int i1, int j1, int i2, int j2, int i3, int j3, int i4, int j4, int p, int q) {
    int wh1 = Get(i1, j1, i2, j2), wh2 = Get(i3, j3, i4, j4);
    int ye1 = Area(i1, j1, i2, j2) - wh1, ye2 = Area(i3, j3, i4, j4) - wh2;
    if (wh1 >= p && wh2 >= q)
        res = min(res, ye1 + ye2);
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
        cin >> m >> n >> p >> q;
        for (int i = 1; i <= m; i++)
            for (int j = 1; j <= n; j++) {
                char c; cin >> c;
                a[i][j] = (c == 'x');
                s[i][j] = s[i - 1][j] + s[i][j - 1] - s[i - 1][j - 1] + a[i][j];
            }
        for (int i1 = 1; i1 <= m; i1++)
        for (int j1 = 1; j1 <= n; j1++)
        for (int i2 = i1; i2 <= m; i2++)
        for (int j2 = j1; j2 <= n; j2++) {
            for (int i4 = i2; i4 > 0; i4--)
            for (int j4 = j1 - 1; j4 > 0; j4--)
            for (int i3 = i4; i3 > 0; i3--)
            for (int j3 = j4; j3 > 0; j3--) {
                Optimize(i1, j1, i2, j2, i3, j3, i4, j4, p, q);
                Optimize(i1, j1, i2, j2, i3, j3, i4, j4, q, p);
            }
            for (int i4 = i1 - 1; i4 > 0; i4--)
            for (int j4 = j2; j4 > 0; j4--)
            for (int i3 = i4; i3 > 0; i3--)
            for (int j3 = j4; j3 > 0; j3--) {
                Optimize(i1, j1, i2, j2, i3, j3, i4, j4, p, q);
                Optimize(i1, j1, i2, j2, i3, j3, i4, j4, q, p);
            }
	    }
        if (res == 1e7)
            cout << "No film today!";
        else   
            cout << res;
    }
	
	return 0;
}