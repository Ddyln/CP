#include <bits/stdc++.h>
using namespace std;

#define Fname ((string) "test")
const int _nt = 1000;
#define endl '\n'

void createTest(int id) {
	ofstream cout((Fname + ".inp").c_str());
	int n = rand() % 10 + 1, m = rand() % 10 + 1, p = rand() % 10 + 1;
    cout << n << ' ' << m << ' ' << p;
	cout.close();
}

signed main() {
	srand(time(NULL));
	for (int i = 1; i <= _nt; i++) {
		createTest(i);
		system("test.exe");
		system("accum.exe");

		if (system(("fc " + Fname + ".out " + Fname + ".ans").c_str()) != 0) {
			cout << "Wrong Answer!!";
			return 0;
		}
	}
	cout << "Passed!";
	return 0;
}