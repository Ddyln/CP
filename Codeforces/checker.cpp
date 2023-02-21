#include <bits/stdc++.h>
using namespace std;

#define Fname ((string) "test")
const int _nt = 500;
#define endl '\n'

void createTest(int id) {
    ofstream cout((Fname + ".inp").c_str());
    int n = 50, q = 100, val = 1e9;
    cout << 1 << endl << n << ' ' << q << endl;
    for (int i = 1; i <= n; i++)
        cout << (rand() % val) * (rand() % val) + 1 << ' ';
    while (q--) {
        int t = rand() % 2 + 1;
        cout << t << ' ';
        if (t == 1) {
            int l = rand() % n + 1;
            int r = rand() % (n - l + 1) + l;
            cout << l << ' ' << r << endl;
        }
        else
            cout << rand() % n + 1 << endl;
    }
    cout.close();
}

signed main() {
    srand(time(NULL));
    for (int i = 1; i <= _nt; i++) {
        createTest(i);
        system((Fname + ".exe").c_str());
        system("test_trau.exe");

        if (system(("fc " + Fname + ".out " + Fname + ".ans").c_str()) != 0) {
            cout << "Wrong Answer!!";
            return 0;
        }
    }
    cout << "Passed!";
    return 0;
}