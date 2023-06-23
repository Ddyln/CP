#include <bits/stdc++.h>
using namespace std;

vector <int> a, b;

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    #ifdef lan_ngu
        freopen("test.inp", "r", stdin);
        freopen("test.out", "w", stdout);
    #endif
    string s;
    cin >> s;
    s += '-';
    int tmp = 0;
    for (int i = 0; i < s.size(); i++)
        if (s[i] == '-')
            a.push_back(tmp), tmp = 0;
        else 
            tmp = tmp * 10 + s[i] - '0';
    
    cin >> s;
    s += '-';
    tmp = 0;
    for (int i = 0; i < s.size(); i++)
        if (s[i] == '-')
            b.push_back(tmp), tmp = 0;
        else 
            tmp = tmp * 10 + s[i] - '0';
    if (a.size() != b.size()) {
        cout << "NO";
        return 0;
    }
    int i = 0, j = 0;
    stack <int> st;
    while (j < b.size()) {
        if (i >= a.size()) {
            if (!st.size() || st.top() != b[j]) {
                cout << "NO";
                return 0;
            }
            st.pop();
            j++;
        }
        else if (a[i] != b[j]) {
            if (st.size() && st.top() == b[j]) {
				st.pop();
				j++;
			}
            else
        		st.push(a[i++]);
        }
        else
            i++, j++;
    }
    cout << "YES";
    return 0;
}
