#include <bits/stdc++.h>
using namespace std;

#define Fname ((string) "test")
#define int long long
#define ii pair <int, int>
#define iii pair <int, ii>
#define fi first
#define se second
#define endl '\n'

const int N = 100;

int n, a[N];

void sol() {
	cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    sort(a + 1, a + 1 + n, greater <int>());
    if (a[1] == a[2]) {
        if (n == 2 || a[n] == a[2]) {
            cout << "NO\n";
            return;
        }
        else
            swap(a[2], a[n]);
    } 
    cout << "YES\n";
    for (int i = 1; i <= n; i++)
        cout << a[i] << ' ';
    cout << endl;
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