#include <bits/stdc++.h>
using namespace std;

#define Fname ((string) "test")
#define int long long
#define ii pair <int, int>
#define iii pair <int, ii>
#define fi first
#define se second
#define endl '\n'

int n, cnt, res;
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
        cin >> n >> s;
        res = cnt = 0;
        for (int i = 0; i < n; i++)
            if (s[i] == '+') 
                res++;
            else
                res--;
        cout << abs(res) << endl;
	}
	
	return 0;
}