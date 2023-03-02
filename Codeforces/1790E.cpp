#include <bits/stdc++.h>
using namespace std;

#define Fname ((string) "test")
#define int long long
#define ii pair <int, int>
#define iii pair <int, ii>
#define fi first
#define se second
#define endl '\n'

vector <int> bin(int n) {
    vector <int> res(0);
    while (n != 0) {
        res.push_back(n % 2);
        n /= 2;
    }
    return res;
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
        int n = 0;
		cin >> n;
        vector <int> a = bin(n);
        bool ok = !a[0];
        int b = 0, c = 0;
        for (int i = 0; ok && i < a.size(); i++)
            if (i < a.size() - 1 && a[i] == a[i + 1] && a[i])
                ok = 0;
            else if (a[i]) {
                b |= ((1 << i) | (1 << (i - 1)));
                c |= (1 << (i - 1));
            }
        if (ok)
            cout << b << ' ' << c << endl;
        else
            cout << "-1\n";
	}
	
	return 0;
}