#include <bits/stdc++.h>
using namespace std;

typedef vector <int> vi;

int base10(char c) {
    if (isdigit(c))
        return c - '0';
    c = tolower(c);
    return c - 'a' + 10;
}

void AddBit(vi& a, int n) {
    reverse(a.begin(), a.end());
    while (n--)
        a.push_back(0);
    reverse(a.begin(), a.end());
}

vi Add(vi a, vi b) {
    if (a.size() < b.size()) swap(a, b);
    while (b.size() < a.size()) b.push_back(0);
    int n = a.size();
    vi res;
    int carry = 0;
    for (int i = 0; i < n; i++) {
        res.push_back((a[i] + b[i] + carry) % 2);
        carry = (((a[i] + b[i] + carry) >> 1) & 1);
    }
    if (carry)
        res.push_back(carry);
    return res;
}

bool cmp(vi a, vi b) {
    if (a.size() < b.size()) swap(a, b);
    while (a.size() > b.size()) b.push_back(0);
    for (int i = 0; i < a.size(); i++)
        if (a[i] != b[i])
            return 0;
    return 1;
}

signed main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    if(fopen("test.inp", "r"))
    {
        freopen("test.inp", "r", stdin);
        freopen("test.out", "w", stdout);
    }
    string a, b;
    cin >> a >> b;
    int n = a.size(), m = b.size();
    n = m - n;
    string tmp = "";
    while (n--) tmp += "0";
    a = tmp + a;
    reverse(a.begin(), a.end());
    reverse(b.begin(), b.end());
    int bit[16][4] = {
        {0, 0, 0, 0},
        {0, 0, 0, 1},
        {0, 0, 1, 0},
        {0, 0, 1, 1},
        {0, 1, 0, 0},
        {0, 1, 0, 1},
        {0, 1, 1, 0},
        {0, 1, 1, 1},
        {1, 0, 0, 0},
        {1, 0, 0, 1},
        {1, 0, 1, 0},
        {1, 0, 1, 1},
        {1, 1, 0, 0},
        {1, 1, 0, 1},
        {1, 1, 1, 0},
        {1, 1, 1, 1},
       
    };
    vi a2, b2;
    for (int i = 0; i < m; i++) {
        int x = base10(a[i]);
        for (int j = 3; j >= 0; j--)
            a2.push_back(bit[x][j]);
    }
    for (int i = 0; i < m; i++) {
        int x = base10(b[i]);
        for (int j = 3; j >= 0; j--)
            b2.push_back(bit[x][j]);
    }
    m *= 4;
    for (int i = m - 1; i >= 4; i--)
        if (a2[i] != b2[i]) {
            cout << "F";
            return 0;
        }
    while (a2.back() == 0) a2.pop_back();
    while (b2.back() == 0) b2.pop_back();
    vi cur(a2.begin(), a2.end()), I(1, 1);
    do {
        cur = Add(cur, I);
        vector <vi> tmp;
        for (int i = 0; i < cur.size(); i++)
            if (cur[i]) {
                vi x(a2.begin(), a2.end());
                AddBit(x, i);
                tmp.push_back(x);
            }
        for (int i = 1; i < tmp.size(); i++)
            tmp[0] = Add(tmp[i], tmp[0]);
        a2.resize(tmp[0].size());
        for (int i = 0; i < tmp[0].size(); i++)
            a2[i] = tmp[0][i];
    } while (!cmp(cur, b2));

    while (a2.size() > 4) {
        while (a2.size() % 4 != 0) a2.push_back(0);
        vi res(4);
        for (int i = 0; i < 4; i++)
            res[i] = a2[i];
        for (int i = 4; i < (int)a2.size(); i += 4) {
            vi tmp(4);
            for (int j = i; j < i + 4; j++) 
                tmp[j - i] = a2[j];
            res = Add(tmp, res);
        } 
        a2 = res;
    }
    while (a2.size() < 4) a2.push_back(0);
    int res = 0;
    for (int i = 0; i < 4; i++) {
        res += (1 << i) * a2[i];
    }
    char Hex[] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'a', 'b', 'c', 'd', 'e', 'f'};
    cout << Hex[res];
    return 0;
}