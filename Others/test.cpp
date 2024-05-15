#include <iostream>
using namespace std;

int main() {
    freopen("test.inp", "r", stdin);
    string s;
    for (int i = 0; i < 5; i++) {
        getline(cin, s);
        cout << s << endl;
    }
    return 0;
}