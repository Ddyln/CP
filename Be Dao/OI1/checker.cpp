#include <bits/stdc++.h>
using namespace std;

#define Fname ((string) "test")
const int _nt = 1000;
#define endl '\n'

void createTest(int id) {
	ofstream cout((Fname + ".inp").c_str());
	cout << "11 12 1\n1 2\n3 4\n1 5\n2 3 \n2 6\n5 6\n6 7\n6 8\n6 9\n6 10\n7 11\n8 11\n";
    for (int i = 1; i <= 4; i++)
        cout << rand() % 11 + 1 << ' ';
	cout.close();
}

signed main() {
	srand(time(NULL));
	for (int i = 1; i <= _nt; i++) {
		createTest(i);
		system("./bridge");
		system(("./test"));

		if (system(("diff " + Fname + ".out " + Fname + ".ans").c_str()) != 0) {
			cout << "Wrong Answer!!";
			return 0;
		}
	}
	cout << "Passed!";
	return 0;
}