#include <bits/stdc++.h>
using namespace std;

#define Fname ((string) "test")
#define int long long
#define ii pair <int, int>
#define iii pair <int, ii>
#define fi first
#define se second
#define endl '\n'
const int MAX = 1e17;

int n;
string s, t;
vector <string> ans;
stack <char> st;
map <pair <stack <char>, ii>, int> mp1, mp2;
map <pair <stack <char>, ii>, bool> vis;

void add(int &a, int &b, const int &c, const int &d) {
    a += c;
    b += d;
    if (a >= MAX)
        a -= MAX, b++;
}

void Try(int i, int j) {
    if (j == n) {
        if (++cnt <= 1000)
            ans.push_back(command);
    }
    else {
        if (i < n) {
            st.push(s[i]);
            Try(i + 1, j);
            st.pop();
        }
        if (st.size() && st.top() == t[j]) {
            st.pop();
            Try(i, j + 1);
            st.push(t[j]);
        }
    }
}

void Find(int i, int j, string command) {
    if (j == n) 
    }
    else {
        if (i < n) {
            st.push(s[i]);
            Find(i + 1, j, command + "1");
            st.pop();
        }
        if (st.size() && st.top() == t[j]) {
            st.pop();
            Find(i, j + 1, command + "2");
            st.push(t[j]);
        }
    }
}

signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	#ifdef lan_ngu
		freopen((Fname + ".inp").c_str(), "r", stdin);
		freopen((Fname + ".out").c_str(), "w", stdout);
	#endif
	// int _nt; cin >> _nt;
	int _nt = 1;
	while (_nt--) {
        cin >> s >> t;
        n = s.size();
        Try(0, 0);
        if (mp2[{st, {0, 0}}])
            cout << mp2[{st, {0, 0}}];
        cout << mp1[{st, {0, 0}}];
        if (!mp2[{st, {0, 0}}] && mp1[{st, {0, 0}}] <= 1000) {
            Find(0, 0, "");
            for (int i = 0; i < ans.size(); i++)
                cout << endl << ans[i];
        }
	}
	
	return 0;
}