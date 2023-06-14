#include <bits/stdc++.h>
using namespace std;

#define Fname ((string) "test")
const int _nt = 1;
#define endl '\n'

void createTest(int id) {
	ofstream cout((Fname + ".inp").c_str());
	
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