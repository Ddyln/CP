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
        cin >> n;
        for (int i = 1; i <= n; i++) 
            cin >> A[i];
        int res = 1e9;
        for (int mask = 0; mask < (1 << n); mask++) {
            vector <int> a, b;
            for (int i = 0; i < n; i++)
                if (mask & (1 << i))
                    a.push_back(A[i + 1]);
                else    
                    b.push_back(A[i + 1]);
            int s = 0;
            for (int i = 1; i < a.size(); i++)
                s += (a[i - 1] < a[i]);
            for (int i = 1; i < b.size(); i++)
                s += (b[i - 1] < b[i]);
            res = min(res, s);
        }
        cout << res << endl;
	}
	
	return 0;
}