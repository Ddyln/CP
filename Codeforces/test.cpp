#include <bits/stdc++.h>
using namespace std;

int sol(string s) {
        if (s.size() == 0)
            return 0;
        stack <int> st;
        int i = 0, cnt = 0, sum = 0, res = 0;
        while (s[i] != '\n')
            i++;
        sum = i;
        st.push(i++);
        while (i < s.size()) {
            cnt = 0;
            while (s[i] == '\t')
                i++, cnt++;
            while (cnt < st.size()) {
                sum -= st.top();
                st.pop();
            }
            cnt = 1;
            bool file = 0;
            while (i < s.size() && s[i] != '\n') {
                if (s[i] == '.')
                    file = 1;
                i++, cnt++; 
            }
            st.push(cnt);
            sum += cnt;
            if (file)
                res = max(res, sum);
            i++;
        }   
        return res;
  }

int main() {
    // string inp = "dir\n\tsubdir1\n\t\tfile1.ext\n\t\tsubsubdir1\n\tsubdir2\n\t\tsubsubdir2\n\t\t\tfile2.ext";
    string inp = "dir\n\tsubdir1\n\t\tfile.ext";
    cout << endl << sol(inp);
    return 0;
}