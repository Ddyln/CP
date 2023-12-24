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
int n, l[N], r[N], c[N];

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
            cin >> l[i];
        set <int> s;
        for (int i = 1; i <= n; i++) {
            cin >> r[i];
            s.insert(r[i]);
        }
        for (int i = 1; i <= n; i++)
            cin >> c[i];
        sort(l + 1, l + 1 + n, greater <int>());
        sort(c + 1, c + 1 + n);
        int res = 0;
        vector <int> v;
        int pos = 1;
        for (int i = 1; i <= n; i++) {
            auto it = s.lower_bound(l[i]);
            v.push_back(*it - l[i]);
            s.erase(it);
        }
        sort(v.begin(), v.end(), greater <int>());
        for (int i = 1; i <= n; i++) 
            res += v[i - 1] * c[i];
        cout << res << endl;
	}
	
	return 0;
}