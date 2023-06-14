#include <bits/stdc++.h>
using namespace std;

#define Fname ((string) "test")
const int _nt = 2;
#define endl '\n'

void createTest(int id) {
	ofstream cout((Fname + ".inp").c_str());
	int n = rand() % 1000 + 1, M = 1e9;
	cout << n << endl;
	for (int i = 1; i <= n; i++)
		cout << rand() % M + 1 << ' ';
	cout.close();
}

signed main() {
	srand(time(NULL));
	for (int i = 1; i <= _nt; i++) {
		createTest(i);
		system(("./" + Fname).c_str());
		system(("./" + Fname + "_trau").c_str());

		if (system(("diff " + Fname + ".out " + Fname + ".ans").c_str()) != 0) {
			cout << "Wrong Answer!!";
			return 0;
		}
	}
	cout << "Passed!";
	return 0;
}