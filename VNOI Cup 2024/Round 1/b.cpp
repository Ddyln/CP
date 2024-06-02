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

int n, a[N], b[N];

signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	#ifdef lan_ngu
        freopen((Fname + ".inp").c_str(), "r", stdin);
        freopen((Fname + ".out").c_str(), "w", stdout);
        // freopen("log.txt", "w", stderr);
    #endif
    
	int _nt; cin >> _nt;
	// int _nt = 1;
	while (_nt--) {
        cin >> n;
        for (int i = 1; i <= n; i++)
            cin >> a[i];
        for (int i = 1; i <= n; i++)
            cin >> b[i];
        for (int i = n; i > 1; i--)
            if (a[i] > b[i]) {
                int x = (a[i] - b[i]);
                if (a[i] - b[i] > 1000000000)
                    a[i - 1] += 2000000000, a[i] -= 1000000000;
                else 
                    a[i - 1] += (a[i] - b[i]) * 2, a[i] = b[i];
            }
        for (int i = 1; i < n; i++)
            if (a[i] - b[i] > 1) {
                int x = a[i] - b[i];
                x = ((x >> 1) << 1);
                a[i + 1] += x / 2;
                a[i] -= x; 
            }
        bool ok = 1;
        for (int i = 1; i <= n; i++) 
            if (a[i] < b[i])
                ok = 0;
        cout << (ok ? "YES\n" : "NO\n");
	}
	
	return 0;
}