#include <bits/stdc++.h>
using namespace std;

void modify(string& s) {
    string t = s;
    int i = 0; 
    s = "";
    while (i < t.size()) {
        if (!isdigit(t[i])) 
            s += t[i++];
        else {
            while (i < t.size() && isdigit(t[i]))
                s += t[i++];
            if (i < t.size() && t[i] == '.')
                s += t[i++];
            while (i < t.size() && isdigit(t[i]))
                s += t[i++];
        }
        s += " ";
    }
    s.pop_back();
}

double evaluate(istream& in) {
    stack <string > ops;
    stack <double > vals;
    string tok;
    while (!in.eof()) {
        in >> tok;
        if (tok == "(");
        else if (tok == "+" || tok == "*") ops.push(tok);
        else if (tok == ")") {
            string op = ops.top(); ops.pop();
            double val2 = vals.top(); vals.pop();
            double val1 = vals.top(); vals.pop();
            if (op == "+") vals.push(val1 + val2);
            else if (op == "*") vals.push(val1 * val2);
        }
        else vals.push(stod(tok));
    }
    return vals.top();
}

int main() {
    string expr = "((12.4+3)*2.4)";
    modify(expr);
    stringstream inp(expr);
    cout << evaluate(inp) << endl;
    return 0;
}