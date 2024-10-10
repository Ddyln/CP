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

vector <vector <int>> mul(vector <vector <int>> A, vector <vector <int>> B) {
    int m = A.size(), n = A[0].size(), p = B[0].size();
    vector <vector <int>> res(m, vector <int>(p, 0));
    for (int i = 0; i < m; i++)
        for (int j = 0; j < p; j++)
            for (int k = 0; k < n; k++)
                (res[i][j] += A[i][k] * B[k][j] % MOD) %= MOD;
    return res;
}

vector <vector <int>> Pow(vector <vector <int>> A, int n) {
    if (n == 1) return A;
    vector <vector <int>> res = Pow(A, n / 2);
    res = mul(res, res);
    if (n % 2 == 1) res = mul(res, A);
    return res;
}

signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	#ifdef lan_ngu
        freopen((Fname + ".inp").c_str(), "r", stdin);
        freopen((Fname + ".out").c_str(), "w", stdout);
    #endif

    int a, b, c, d, n;
    cin >> a >> b >> c >> d >> n;
    if (n == 1) cout << a;
    else if (n == 0) cout << b;
    else {
        vector <vector <int>> I = {{0, 1, 0, 0, 0}, {0, 0, 1, 0, 0}, {0, 2, 1, 0, 0}, {0, 0, 0, 0, 1}, {1, 1, 1, 2, 3}};
        vector <vector <int>> F0 = {{d}, {c}, {c + 2 * d}, {b}, {a}};
        
        vector <vector <int>> res = Pow(I, n - 1);
        res = mul(res, F0);
        cout << res.back()[0];
    }
	
	return 0;
}