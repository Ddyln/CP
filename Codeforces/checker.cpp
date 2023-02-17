#include <bits/stdc++.h>
using namespace std;

#define Fname ((string) "test")
const int _nt = 200;
#define endl '\n'

void createTest(int id) {
    ofstream cout((Fname + ".inp").c_str());
    int n = 2, val = 20;
    bool c[1000];
    for (int i = 1; i <= n; i++)
        c[i] = 0;
    cout << n << endl;
    for (int i = 1; i <= n; i++) {
        while (1) {
            int x = rand() % n + 1;
            if (!c[x]) {
                c[x] = 1;
                cout << x << ' ';
                break;
            }
        }
    }
    cout << endl;
    for (int i = 1; i <= n; i++) {
        int sign = rand() % 2;
        if (sign == 1)
            cout << rand() % val << ' ';
        else
            cout << -(rand() % val) << ' ';
    }
    cout.close();
}

signed main() {
    srand(time(NULL));
    for (int i = 1; i <= _nt; i++) {
        createTest(i);
        system((Fname + ".exe").c_str());
        system("trau.exe");

        if (system(("fc " + Fname + ".out " + Fname + ".ans").c_str()) != 0) {
            cout << "Wrong Answer!!";
            return 0;
        }
    }
    cout << "Passed!";
    return 0;
}