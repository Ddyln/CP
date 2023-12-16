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

int n, cnt[26], res;
string s, t;
bool check[N];

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
        cin >> n >> s;
        memset(cnt, 0, sizeof cnt);
        memset(check, 0, sizeof check);
        for (int i = 0; i < n; i++)
            cnt[s[i] - 'a']++;
        int ch = 25;
        t = "";
        for (int i = 0; i < n; i++) {
            while (!cnt[ch]) ch--;
            cnt[s[i] - 'a']--;
            if (s[i] - 'a' != ch) 
                continue;
            check[i] = 1;
            t += s[i];
        }
        res = t.size();
        reverse(t.begin(), t.end());
        for (int i = 0; i < n; i++)
            if (s[i] == t.back())
                res--;
        ch = 0;
        for (int i = 0; i < n; i++)
            if (check[i])
                s[i] = t[ch++];
        t = s;
        sort(t.begin(), t.end());
        if (s != t)
            cout << "-1\n";
        else
            cout << res << endl;
	}
	
	return 0;
}