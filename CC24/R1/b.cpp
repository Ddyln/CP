#include <bits/stdc++.h>
using namespace std;

#define Fname ((string) "test")
#define int long long
#define ii pair <int, int>
#define iii pair <int, ii>
#define fi first
#define se second
#define endl '\n'

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
        int A = 0, B = 0, n, a;
        cin >> n >> a >> A;
        B = A;
        for (int i = 1; i < n - 1; i++) {
            int tmp;
            cin >> tmp;
            A &= tmp;
            B |= tmp;
        }
        if (A == B)
            cout << (A == 0 ? "1 1\n" : "1 0\n");
        else
            cout << "1 0\n";
	}
	
	return 0;
}