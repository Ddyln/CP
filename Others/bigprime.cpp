// http://csloj.ddns.net/problem/10013
#include <bits/stdc++.h>
using namespace std;

#define Fname ((string) "test")
#define int long long
#define ii pair <int, int>
#define iii pair <int, ii>
#define fi first
#define se second
#define endl '\n'

int MOD;

int Pow(int n, int k) {
	if (k < 2)
		return (k ? n : 1);
	int tmp = Pow(n, k / 2);
	tmp = tmp * tmp % MOD;
	return (k % 2 ? tmp * n % MOD : tmp);
}

bool Prime(int n) {
    return ((Pow(2, n) - 2 + n) % n == 0);
}

signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	#ifdef lan_ngu
		freopen((Fname + ".inp").c_str(), "r", stdin);
		freopen((Fname + ".out").c_str(), "w", stdout);
	#endif 

	// int _nt; cin >> _nt;
	// int _nt,n  = 1;
	while (cin >> MOD) 
        cout << Prime(MOD) << endl;
	
	return 0;
}