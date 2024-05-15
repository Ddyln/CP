#include <bits/stdc++.h>
using namespace std;

#define Fname ((string) "test")
#define int long long
#define ii pair <int, int>
#define iii pair <int, ii>
#define fi first
#define se second
#define endl '\n'

int cnt[26];
string s;
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
        memset(cnt, 0, sizeof cnt);
        cin >> s;
        for (char c : s)
            cnt[c - 'a']++;
        int m = 0;
        for (int i = 0; i < 26; i++) m = max(m, cnt[i]);
        cout << (int)s.size() - m << endl; 
	}  
	
	return 0;
}