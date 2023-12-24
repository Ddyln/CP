#include <bits/stdc++.h>
using namespace std;

#define Fname ((string) "test")
#define int long long
#define ii pair <int, int>
#define iii pair <int, ii>
#define fi first
#define se second
#define endl '\n'

const int N = 104;
int n, x[N], y[N];

bool checkUp() {
    for (int i = 1; i <= n; i++)
        if (y[i] > 0)
            return 0;
    return 1;
}

bool checkDown() {
    for (int i = 1; i <= n; i++)
        if (y[i] < 0)
            return 0;
    return 1;
}

bool checkLeft() {
    for (int i = 1; i <= n; i++)
        if (x[i] < 0)
            return 0;
    return 1;
}

bool checkRight() {
    for (int i = 1; i <= n; i++)
        if (x[i] > 0)
            return 0;
    return 1;
}

bool check() {
    return (checkUp() || checkDown() || checkLeft() || checkRight());
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
        cin >> n;
        for (int i = 1; i <= n; i++) 
            cin >> x[i] >> y[i];
        cout << (check() ? "YES\n" : "NO\n");
	}
	
	return 0;
}