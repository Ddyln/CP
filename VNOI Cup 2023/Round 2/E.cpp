#include <bits/stdc++.h>
using namespace std;

#define Fname ((string) "test")
#define int long long
#define ii pair <int, int>
#define iii pair <int, ii>
#define fi first
#define se second
#define endl '\n'
const int MOD = 1e9 + 7;
const int N = 103;

int X[N], n, m, Y[N], a[N][N], k, M, cnt[10123];
bool inside(int i, int j) {
    return (i > 0 && j > 0 && i <= m && j <= n);
}
bool check() {
    for (int i = 1; i <= m; i++)
        for (int j = 1; j <= n; j++) 
            if (a[i][j]) {
            int ni = i, nj = j;
            while (inside(--ni, --nj)) {
                if (a[ni][nj])
                    return 0;
            }
            ni = i, nj = j;
            while (inside(--ni, ++nj)) {
                if (a[ni][nj])
                    return 0;
            }
            ni = i, nj = j;
            while (inside(++ni, --nj)) {
                if (a[ni][nj])
                    return 0;
            }
            ni = i, nj = j;
            while (inside(++ni, ++nj)) {
                if (a[ni][nj])
                    return 0;
            }
        }
    return 1;
}
void Try(int i, int j, int num) {
    if (i > m) {
        if (!check())
            return;
           cnt[num]++;
        M = max(M, num);
        return;
    }
    if (a[i][j]) {
        if (j == n)
            Try(i + 1, 1, num);
        else
            Try(i, j + 1, num);
    }
    else {
        a[i][j] = 1;
        if (j == n) 
            Try(i + 1, 1, num + 1);
        else
            Try(i, j + 1, num + 1);
        
        a[i][j] = 0;
        if (j == n)
            Try(i + 1, 1, num);
        else
            Try(i, j + 1, num);
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
		// Code here
        cin >> m >> n >> k;
        for (int i = 1; i <= k; i++) {
            cin >> X[i] >> Y[i];
            a[X[i]][Y[i]] = 1;
        }
        Try(1, 1, k);
        cout << M - k<< ' ' << cnt[M];
	}
	
	return 0;
}