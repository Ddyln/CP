#include <bits/stdc++.h>
using namespace std;

#define Fname ((string) "test")
#define int long long
#define ii pair <int, int>
#define iii pair <int, ii>
#define fi first
#define se second
#define endl '\n'

int p2[30], cnt[30], Add[30];

signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	#ifdef lan_ngu
        freopen("test.inp", "r", stdin);
        freopen("test.out", "w", stdout);
    #endif
    p2[0] = 1;
    for (int i = 1; i <= 29; i++)
        p2[i] = p2[i - 1] << 1;
	int _nt; cin >> _nt;
	// int _nt = 1;
	while (_nt--) {
        int t, x; 
        cin >> t >> x;
        if (t == 1) {
            cnt[x]++;
        }
        else {
            bool ok = 1;
            memset(Add, 0, sizeof Add);
            for (int i = 29; i >= 0 && ok; i--) {
                if (x & (1 << i)) {
                    int j = i, tmp = (1 << i);
                    while (tmp > 0 && j >= 0) {
                        while (j >= 0 && cnt[j] == 0) j--;
                        if (j < 0) {
                            break;
                            ok = 0;
                        }
                        int l = 1, r = cnt[j];
                        while (l < r) {
                            int m = (l + r + 1) >> 1;
                            if (m * p2[j] <= tmp) 
                                l = m;
                            else
                                r = m - 1;
                        }
                        tmp -= p2[j] * l;
                        cnt[j] -= l;
                        Add[j] += l;
                        j--; 
                    }
                    if (tmp > 0) {
                        ok = 0;
                        break;
                    }

                }
            }
            for (int i = 0; i < 30; i++)
                cnt[i] += Add[i];
            cout << (ok ? "YES\n" : "NO\n");
        }
	}
	
	return 0;
}