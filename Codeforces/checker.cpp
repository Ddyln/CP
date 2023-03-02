#include <bits/stdc++.h>
using namespace std;

#define Fname ((string) "test")
const int _nt = 20000;
#define endl '\n'

void createTest(int id) {
    ofstream cout((Fname + ".inp").c_str());
    int n = 500;
    cout << n << endl;
    for (int i = 1; i <= n; i++) {
        int len = rand() % 40 + 30, ban = rand() % 26;
        for (int j = 0; j < len; j++) {
            int tmp = rand() % 26;
            if (tmp == ban)
                continue;
            cout << char(tmp + (int)'a');
        }
        cout << endl;
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