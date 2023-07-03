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
vector <char> st;
map <pair <vector <char>, ii>, int> mp1, mp2;
map <pair <vector <char>, ii>, bool> vis;

void add(int &a, int &b, const int &c, const int &d) {
    a += c;
    b += d;
    if (a >= MAX)
        a -= MAX, b++;
}

bool check(int i, int j) {
    bool ok = 1;
    vector <char> tmp = st;
    while (j < n) {
        if (i >= n) {
            if (!st.size() || st.back() != t[j]) {
                ok = 0;
                break;
            }
            st.pop_back();
            j++;
        }
        else if (s[i] != t[j]) {
            if (st.size() && st.back() == t[j]) {
				st.pop_back();
				j++;
			}
            else
        		st.push_back(s[i++]);
        }
        else
            i++, j++;
    }
    st = tmp;
    return ok;
}

void Try(int i, int j) {
    vis[{st, {i, j}}] = 1;
    if (j < n) {
        if (i < n) {
            st.push_back(s[i]);
            if (check(i + 1, j)) {
                if (!vis[{st, {i + 1, j}}])
                    Try(i + 1, j);
                vector <char> tmp = st;
                tmp.pop_back();
                add(mp1[{tmp, {i, j}}], mp2[{tmp, {i, j}}], mp1[{st, {i + 1, j}}], mp2[{st, {i + 1, j}}]);
            }
            st.pop_back();
        }
        if (st.size() && st.back() == t[j]) {
            st.pop_back();
            if (check(i, j + 1)) {
                if (!vis[{st, {i, j + 1}}])
                    Try(i, j + 1);
                vector <char> tmp = st;
                tmp.push_back(t[j]);
                add(mp1[{tmp, {i, j}}], mp2[{tmp, {i, j}}], mp1[{st, {i, j + 1}}], mp2[{st, {i, j + 1}}]);
            }
            st.push_back(t[j]);
        }
    }
}

void Find(int i, int j, string command) {
    if (j == n) {
        ans.push_back(command);
    }
    else {
        if (i < n) {
            st.push_back(s[i]);
            Find(i + 1, j, command + "1");
            st.pop_back();
        }
        if (st.size() && st.back() == t[j]) {
            st.pop_back();
            Find(i, j + 1, command + "2");
            st.push_back(t[j]);
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
        mp1[{st, {n, n}}] = 1;
        Try(0, 0);
        if (mp2[{st, {0, 0}}]) {
            cout << mp2[{st, {0, 0}}];
            int n = 17 - to_string(mp1[{st, {0, 0}}]).size();
            while (n--)
                cout << "0";
        }
        cout << mp1[{st, {0, 0}}];
        if (!mp2[{st, {0, 0}}] && mp1[{st, {0, 0}}] <= 1000) {
            Find(0, 0, "");
            for (int i = 0; i < ans.size(); i++)
                cout << endl << ans[i];
        }
	}
	
	return 0;
}