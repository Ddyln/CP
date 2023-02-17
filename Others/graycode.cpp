//https://cses.fi/problemset/task/2205
#include <bits/stdc++.h>
using namespace std;

#define Fname ((string) "test")
#define int long long
#define ii pair <int, int>
#define iii pair <int, ii>
#define fi first
#define se second
#define endl '\n'

int n;
bool check[(1 << 16) + 1];

string bit(int a) {
    string s = "";
    while (a) {
        s = char(a % 2 + '0') + s;
        a /= 2;
    }
    while (s.size() < n)
        s = "0" + s;
    return s;
}

void Print(int a) {
    check[a] = 1;
    cout << bit(a) << endl;
    for (int i = 0; i < n; i++) {
        if (!check[a ^ (1 << i)]) {
            Print(a ^ (1 << i));
            break;
        }
    }
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
        Print(0);
	}
	
	return 0;
}