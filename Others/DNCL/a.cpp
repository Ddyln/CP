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
const int N = 1003;

char a[N][N];
int n;

int Pow(int n, int k) {
    if (k == 0) return 1;
    if (k == 1) return n;
    int res = Pow(n, k / 2);
    res = res * res % MOD;
    return (k % 2 == 1 ? res * n % MOD : res);
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
            for (int j = 1; j <= n; j++) 
                cin >> a[i][j];
        int res = 0;
        for (int i = 1; i <= n; i++) {
            int cnt = 0, sum = 0;
            for (int j = 1; j <= n; j++)
                if (a[i][j] == '#') cnt++;
                else if (cnt) (sum += Pow(cnt, cnt)) %= MOD, cnt = 0;
            if (cnt) (sum += Pow(cnt, cnt)) %= MOD;
            res = max(res, sum);
        }
        cout << res << ' ';
        res = 0;
        for (int j = 1; j <= n; j++) {
            int cnt = 0, sum = 0;
            for (int i = 1; i <= n; i++)
                if (a[i][j] == '#') cnt++;
                else if (cnt) (sum += Pow(cnt, cnt)) %= MOD, cnt = 0;
            if (cnt) (sum += Pow(cnt, cnt)) %= MOD;
            res = max(res, sum);
        }
        cout << res;
	}
	
	return 0;
}