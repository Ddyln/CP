#include <bits/stdc++.h>
using namespace std;
void nhap(queue<int> &q, queue<int> &ans)
{
string s;
cin >> s;
string t;
// getline(cin, t);
cin >> t;
for (int i = 0; i < s.size(); ++i)
{

if (s[i] == '-')
s[i] = ' '; // dùng để tách số thứ tự

}
for (int i = 0; i < t.size(); ++i)
{

if (t[i] == '-')
t[i] = ' '; // dùng để tách số thứ tự

}
stringstream token(s);
string number;
while (token >> number)
{

int num = stoi(number);
// cout << num << ' ';
q.push(num);
}
// cout << endl;
stringstream token2(t);
while (token2 >> number)
{
ans.push(stoi(number));
}
}
void move(queue<int> &q, stack<int> &st, queue<int> &ans)
{
    while (q.size())
    {
        if (q.front() == ans.front())
        { // Nếu toa tàu từ A có thể qua C thì chuyển qua C luôn
            q.pop();
            ans.pop();
        }
        else
        {

            if (st.size() && st.top() == ans.front())
            { // Nếu toa tàu từ B chuyển qua C được thì chuyển luôn

                ans.pop();
                st.pop();

            }
            else
            { // Nếu cả A và B không chuyển được thì chuyển tạm A qua B
                st.push(q.front());
                q.pop();
            }
        }   
    }
    while (st.size())
    {

        if (st.top() == ans.front())
        { // Nếu toa tàu từ B chuyển qua C được thì chuyển luôn

            st.pop();
            ans.pop();
        }
        else
        { // Không chuyển được từ B qua C nên không thể xếp tiếp

            cout << "NO";

            return;
        }
    }
    cout << "YES";
}
int main()
{
    #ifdef lan_ngu
        freopen("test.inp", "r", stdin);
        freopen("test.ans", "w", stdout);
    #endif
queue<int> q; // Lưu đoàn tàu A
queue<int> ans; // Lưu đoàn tàu C
stack<int> st; // Lưu đoàn tàu B
nhap(q, ans);
move(q, st, ans);
return 0;
}