// http://csloj.ddns.net/problem/603
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

int Pow(int n, int k) {
	if (k < 2)
		return (k ? n : 1);
	int tmp = Pow(n, k / 2);
	tmp = tmp * tmp % MOD;
	return (k % 2 ? tmp * n % MOD : tmp);
}

int inv(int a, int b) {
	return a * Pow(b, MOD - 2) % MOD;
}

int C(int n, int k) {
	if (n < k)
		return 0;
	int num = 1, deno = 1;
	for (int i = n - k + 1; i <= n; i++)
		num = num * i % MOD, deno = deno * (i - n + k) % MOD;
	return inv(num, deno);
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
		int n, k;
		cin >> n >> k;
		cout << C(n - k + 1, k);
	}
	
	return 0;
}