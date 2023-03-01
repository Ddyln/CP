#include <bits/stdc++.h>
using namespace std;

void InputArray(vector <float> &a) {
    int n = 0;
    cin >> n;
    a.resize(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
}

void OutputArray(const vector <float> &a) {
    for (int i = 0; i < a.size(); i++)
        cout << a[i] << " ";
}

int main() {
    vector <float> a;
    InputArray(a);
    OutputArray(a);
    return 0;
}