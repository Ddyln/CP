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
        for (int i = 1; i <= n; i++)
            cin >> a[i];
        int i = 1, j = n;
        while (i < n && a[i] == a[i + 1]) i++;
        while (j > 1 && a[j] == a[j - 1]) j--;
        if (i >= j)
            cout << "0\n";
        else if (a[1] == a[n])
            cout << n - i - (n - j + 1) << endl;
        else
            cout << min(n - i, j - 1) << endl;
	}
	
	return 0;
}