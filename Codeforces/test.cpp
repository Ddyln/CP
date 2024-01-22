#include <bits/stdc++.h>
using namespace std;

#define Fname ((string) "test")
#define int long long
#define ii pair <int, int>
#define iii pair <int, ii>
#define fi first
#define se second
#define endl '\n'
const int N = 25;

int n, A[N];

signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	#ifdef lan_ngu
        freopen((Fname + ".inp").c_str(), "r", stdin);
        freopen((Fname + ".ans").c_str(), "w", stdout);
    #endif

	int _nt; cin >> _nt;
	// int _nt = 1;
	while (_nt--) {
        map <int, int> a[10];
        a[1][1]++, a[1][3]++;
        a[2][2]++, a[2][3]++;
        a[3][4]++;
        a[4][5]++;
        a[5][5]++, a[4][6]++;
        a[6][4]++, a[6][6]++;
        vector <int> v(6, 0);
        for (int i = 0; i < 6; i++)
            v[i] = i + 1;
        int ans = 0;
        do {
            bool ok = 1;
            for (int i = 0; i < 6; i++)
                if (a[i + 1][v[i]])
                    ok = 0;
            if (ok) {
                ans++;
            }
        } while (next_permutation(v.begin(), v.end()));
        cerr << ans;
	}
	
	return 0;
}