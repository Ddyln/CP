#include <bits/stdc++.h>
using namespace std;

#define Fname ((string) "test")
#define int long long
#define ii pair <int, int>
#define iii pair <int, ii>
#define fi first
#define se second
#define endl '\n'
const int N = 1e5 + 5;

int n, a[N];

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
        cin >> n;
        int s = 0;
        for (int i = 1; i <= n; i++) {
            cin >> a[i];
            s += a[i];
            a[i] %= 3;
        }
        s %= 3;
        if (s == 0)
            cout << "0\n";
        else {
            int move = 3 - s;
            for (int i = 1; i <= n; i++)
                if (a[i] == s)  
                    move = 1;
            cout << move << endl;
        }
	}
	
	return 0;
}