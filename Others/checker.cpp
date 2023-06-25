#include <bits/stdc++.h>
using namespace std;

#define Fname ((string) "test")
const int _nt = 1000000;
#define endl '\n'
int n = 10;

vector <int> a(10);

void createTest(int id) {
	ofstream cout((Fname + ".inp").c_str());
	for (int i = 0; i < n; i++) 
		cout << i + 1 << (i == n - 1 ? " " : "-");
	// unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
	// shuffle (a.begin(), a.end(), std::default_random_engine(seed));
	for (int i = 0; i < n; i++) 
		cout << a[i] << (i == n - 1 ? " " : "-");
	next_permutation(a.begin(), a.end());
	cout.close();
}

signed main() {
	srand(time(NULL));
	for (int i = 0; i < n; i++)
		a[i] = i + 1;
	for (int i = 1; i <= _nt; i++) {
		createTest(i);
		system((".\\" + Fname).c_str());
		system((".\\" + Fname + "_trau").c_str());

		if (system(("fc " + Fname + ".out " + Fname + ".ans").c_str()) != 0) {
			cout << "Wrong Answer!!";
			return 0;
		}
	}
	cout << "Passed!";
	return 0;
}