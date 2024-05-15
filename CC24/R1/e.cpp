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
const int N = 2e3 + 5;

bool nonPrime[N];
vector <int> mask[N];

int Pow(int n, int k) {
    if (k < 2) return (k == 1 ? n : 1);
    int res = Pow(n, k / 2);
    res = res * res % MOD;
    return (k & 1 ? res * n % MOD : res);
}

int inv(int n) {
    return Pow(n, MOD - 2);
}

int lcm(int a, int b) {
    int s = a * b % MOD;
    return s * inv(__gcd(a, b)) % MOD;
}

vector <int> sieve(int n) {
    vector <int> res;
    nonPrime[1] = 1;
    for (int i = 2; i * i <= n; i++)
        if (!nonPrime[i]) {
            for (int j = i * i; j <= n; j += i)
                nonPrime[j] = 1;
            // cnt++;
        }
    for (int i = 2; i <= n; i++)
        if (!nonPrime[i]) {
            res.push_back(i);
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

	// int _nt; cin >> _nt;
	int _nt = 1;
	while (_nt--) {
        cin >> n;
        for (int i = 1; i <= n; i++)
            cin >> a[i];
        if (n <= 211) {
            vector <int> pr = sieve(211);
            for (int i = 1; i <= n; i++) {
                int tmp = a[i];
                mask[i].resize(pr.size());
                while (tmp > 1) {
                    for (int j = 0; j < pr.size() && tmp > 1; j++)
                        while (tmp % pr[j] == 0) {
                            mask[i][j]++;
                            tmp /= pr[j];
                        }
                }
            }
            int res = 1;
            for (int i = 1; i <= n; i++) {
                vector <int> tmp(pr.size());
                res = res * a[i] % MOD;
                for (int j = 0; j < pr.size(); j++)
                    res
                for (int )
            }
        }
        else {

        }
	}
	
	return 0;
}