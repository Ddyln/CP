#include <bits/stdc++.h>
using namespace std;

#define Fname ((string) "seq")
#define int long long
#define fi first
#define se second
#define endl '\n'
#define line vector <int>
#define matrix vector <line>
const int MOD = 1e9;

int k, n;

matrix mul(const matrix &A, const matrix &B) {
    int m = A.size(), p = A[0].size(), n = B[0].size();
    matrix C(m, line(n, 0));
    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++)
            for (int k = 0; k < p; k++)
                (C[i][j] += A[i][k] * B[k][j]) %= MOD;
    return C;
}

matrix Pow(matrix A, int n) {
    if (n == 1)
        return A;
    matrix res = Pow(A, n / 2);
    res = mul(res, res);
    return (n & 1 ? mul(res, A) : res);
}

signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	#ifdef lan_ngu
        freopen("test.inp", "r", stdin);
        freopen("test.out", "w", stdout);
    #endif
	int _nt; cin >> _nt;
	// int _nt = 1;
	while (_nt--) {
		// Code here
        cin >> k;
        matrix B(k, line(k, 0)), f(k, line(1, 0));
        for (int i = 0; i < k; i++) {
            cin >> f[i][0];
        }
        for (int i = 0; i < k; i++) {
            if (i < k - 1)
                B[i][i + 1] = 1;
            cin >> B[k - 1][k - i - 1];
        }
        cin >> n;
        if (n <= k)
            cout << f[n - 1][0] << endl;
        else
            cout << mul(Pow(B, n - k), f)[k - 1][0] << endl;
	}   
	
	return 0;
}