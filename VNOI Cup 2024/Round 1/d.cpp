#include <bits/stdc++.h>
using namespace std;

#define Fname ((string) "test")
#define int long long
#define ii pair <int, int>
#define iii pair <int, ii>
#define fi first
#define se second
#define endl '\n'
const int N = 2e5 + 5;

int n, x[N];

int cal(int i) {
    int &a = x[i - 2], &b = x[i - 1], &c = x[i];
    int x = b - a, y = c - b;
    if (x == y) {
        a = c = b;
        return x * 2;
    }
    int res = min(x, y) * 2;
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
            cin >> x[i];    
        if (n == 2) {
            cout << (x[1] + x[2]) / 2 << endl;
            continue;
        }
        int res = 0;
        for (int i = 3; i <= n; i++)
            res += cal(i);
        cout << res << endl;
	}
	
	return 0;
}