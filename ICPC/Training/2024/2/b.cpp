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

	int _nt; cin >> _nt;
	// int _nt = 1;
	while (_nt--) {
        int s = 0;
        for (int i = 0; i < 4; i++) {
            int a;
            cin >> a;
            s += (a > 0);
        }
        if (s == 0) cout << "Typically Otaku\n";
        else if (s == 1) cout << "Eye-opener\n";
        else if (s == 2) cout << "Young Traveller\n";
        else if (s == 3) cout << "Excellent Traveller\n";
        else cout << "Contemporary Xu Xiake\n";
	}
	
	return 0;
}