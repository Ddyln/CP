#include <bits/stdc++.h>
using namespace std;

#define Fname ((string) "test")
#define int long long
#define ii pair <int, int>
#define iii pair <int, ii>
#define fi first
#define se second
#define endl '\n'
const int INF = 1e18;
const int N = 5003;

int n, k, d, f[N][N][2], a[N], b[N], t[N];

void upd(int& f, int val) {
    if (f == -1) f = val;
    else f = min(f, val);
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
        cin >> n >> k >> d;
        for (int i = 1; i <= n; i++)
            cin >> t[i];
        for (int i = 1; i <= k; i++)
            cin >> a[i];
        for (int i = 1; i <= k; i++)
            cin >> b[i];
        // f[i][j][k]: tg thuc hien cong viec 1-i, nguoi cuoi cung thuc hien (0/1) la k, nguoi con lai da nghi j cv
        // memset(f, -1, sizeof f);
        // for (int i = 1; i < n; i++)
        //     for (int j = 1; j <= d; j++)
        //         for (int k = 0; k < 2; k++) 
        //             if (f[i][j][k]) {
        //                 int f1 = INF, f2 = INF;
        //                 if (j < d) 
        //                     upd(f[i + 1][j + 1][k], f[i][j][k] + (t[i] == t[i + 1] ? b[t[i + 1]] : a[t[i + 1]]));
        //                 upd(f[i + 1][1][k ^ 1], f[i][j][k] + a[t[i + 1]]);
        //             }
        // cout << f[2][1][1] << endl;
        // int res = INF;
        // for (int i = 1; i <= d; i++)
        //     res = min(res, min(f[n][i][0], f[n][i][1]));
        // cout << res << endl;
        if (n <= 20) {
            int M = (1 << n), res = INF;
            vector <int> A, B;
            for (int mask = 1; mask < M; mask++) {
                for (int i = 0; i < n; i++)
                    if (mask & (1 << i))
                        A.push_back(i + 1);
                    else
                        B.push_back(i + 1);
                A.push_back(n + 1);
                B.push_back(n + 1);
                bool ok = 1;
                for (int i = 1; i < A.size(); i++)
                    if (A[i] - A[i - 1] > d) 
                        ok = 0;
                for (int i = 1; i < B.size(); i++)
                    if (B[i] - B[i - 1] > d)
                        ok = 0;
                if (!ok) continue;
                int s = 0;
                for (int i = 0; i < (int)A.size() - 1; i++) {
                    if (i) {
                        if (t[A[i]] == t[A[i - 1]])
                            s += b[t[A[i]]];
                        else
                            s += a[t[A[i]]];
                    }
                    else 
                        s += a[t[A[i]]];
                }
                for (int i = 0; i < (int)B.size() - 1; i++) {
                    if (i) {
                        if (t[B[i]] == t[B[i - 1]])
                            s += b[t[B[i]]];
                        else
                            s += a[t[B[i]]];
                    }
                    else 
                        s += a[t[B[i]]];
                }
                if (s < res) cerr << mask << endl;
                res = min(res, s);
            }
            cout << res << endl;
        }
        else {
            int res = a[1];
            for (int i = 2; i <= n; i++)
                res += b[i];
            cout << res << endl;
        }
	}
	
	return 0;
}