#include <bits/stdc++.h>
using namespace std;

#define Fname ((string) "test")
#define ii pair <int, int>
#define iii pair <int, ii>
#define fi first
#define se second
#define endl '\n'
const int N = 51 * 51;

int n, a[N];

void sol() {
	cin >> n;
    for (int i = 1; i <= n * n; i++)
        if (i % 2 == 1)
            a[i] = (i + 1) / 2;
        else
            a[i] = n * n - i / 2 + 1;
    for (int i = 1; i <= n; i++) {
        if (i % 2 == 1)
            for (int j = (i - 1) * n + 1; j <= (i - 1) * n + n; j++)
                cout << a[j] << ' ';
        else
            for (int j = (i - 1) * n + n; j >= (i - 1) * n + 1; j--)
                cout << a[j] << ' ';
        cout << endl;
    }
}

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
		sol();
	}
	
	return 0;
}