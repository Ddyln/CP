#include <bits/stdc++.h>
using namespace std;

#define Fname ((string) "test")
#define int long long
#define ii pair <int, int>
#define iii pair <int, ii>
#define fi first
#define se second
#define endl '\n'

const int N = 1e6 + 5;

int n, a[N * 2], f[N], check[N];
map <int, int> mp;

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
        for (int i = 1; i <= n; i++) {
            cin >> a[i];
            check[i - 1] = 0;
        }
        check[n] = 0;
        int x = 0, sum = 0, res = 0;
        mp.clear();
        for (int i = 1; i <= n; i++) {
            check[a[i]] = 1;
            while (check[x]) x++;
            mp[x]++;
            sum += x;
        }
        res = sum;
        for (int i = 1; i < n; i++) {
            auto it = mp.upper_bound(a[i]);
            stack <int> st;
            for (auto it2 = it; it2 != mp.end(); it2++) {
                sum += (a[i] - it2->fi) * it2->se;
                mp[a[i]] += it2->se;
                st.push(it2->fi);
            }
            while (st.size()) {
                mp.erase(st.top());
                st.pop();
            }
            mp[n] = 1;
            res = max(res, sum += n);
        }
        cout << res << endl;
	}
	
	return 0;
}