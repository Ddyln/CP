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
int n, a[N], k;

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
        cin >> n >> k;
        int cnt[3] = {0};
        for (int i = 1; i <= n; i++) {
            cin >> a[i];
            if (a[i] == k)
                cnt[2]++;
            else 
                cnt[a[i] < k]++;
        }
        if (cnt[0] && cnt[1] || cnt[2] > 0 && cnt[2] < n) {
            cout << "-1\n";
            continue;
        }
        if (cnt[2] == n) {
            cout << "0\n";
            continue;
        }
        int goal = 0;
        for (int i = 1; i <= n; i++) 
            goal = __gcd(goal, abs(a[i] - k));
        int res = 0;
        for (int i = 1; i <= n; i++)
            res += abs(a[i] - k) / goal - 1;
        cout << res << endl;
	}
	
	return 0;
}