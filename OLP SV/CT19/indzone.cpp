#include <bits/stdc++.h>
using namespace std;

#define Fname ((string) "test")
#define int long long
#define ii pair <int, int>
#define iii pair <int, ii>
#define fi first
#define se second
#define endl '\n'
const int MOD = 998244353;
vector <vector <int>> I(3, vector <int>(3)), f(3, vector <int>(3)), C(3, vector <int>(3));

vector <vector <int>> mul(const vector <vector <int>>& A, const vector <vector <int>>& B) {
	int m = 2, p = 2, n = 2;
	for (int i = 1; i <= m; i++)
		for (int j = 1; j <= n; j++) {
			C[i][j] = 0;
			for (int k = 1; k <= p; k++) 
				(C[i][j] += A[i][k] * B[k][j]) %= MOD;
		}
	return C;
}

vector <vector <int>> Pow(vector <vector <int>> A, int n) {
	if (n == 1)
		return A;
	vector <vector <int>> res;
	res = Pow(A, n / 2);
	res = mul(res, res);
	return (n & 1 ? mul(res, A) : res);
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
        int n;
        cin >> n;
		I[1][1] = 0, I[1][2] = 1;
		I[2][1] = 1, I[2][2] = 1;
		f[1][1] = 0, f[2][1] = 1;
		I = Pow(I, ++n);
		int a = (I[1][1] * f[1][1] % MOD + I[1][2] * f[2][1] % MOD) % MOD,
			b = (I[2][1] * f[1][1] % MOD + I[2][2] * f[2][1] % MOD) % MOD;
		cout << a * b % MOD;
	}
	
	return 0;
}
