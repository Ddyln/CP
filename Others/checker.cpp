#include <bits/stdc++.h>
using namespace std;

#define Fname ((string) "test")
const int _nt = 500;
#define endl '\n'

int a, b, c, d, k;

void createTest(int id) {
	ofstream cout((Fname + ".inp").c_str());
	int MAX = 1e1;
	a = rand() % MAX + 1, b = rand() % MAX + 1;
	c = rand() % MAX + 1, d = rand() % MAX + 1;
	k = rand() % MAX + 1;
	if (a > b)
		swap(a, b);
	if (c > d)
		swap(c, d);
	cout << a << ' ' << b << ' ' << c << ' ' << d << ' ' << k;
	cout.close();
}

bool in(int a, int b, int c) {
	return (c >= a && c <= b);
}

signed main() {
	srand(time(NULL));
	for (int i = 1; i <= _nt; i++) {
		createTest(i);
		system((Fname + ".exe").c_str());
		system((Fname + "_trau.exe").c_str());

		ifstream cin("test.out");
		int a1 = 0, b1 = 0, r1 = 0, r2 = 0;
		cin >> a1 >> b1;
		r1 = (a1 + b1) % k;
		cin.close();

		ifstream cin1("test.ans");
		int a2 = 0, b2 = 0;
		cin1 >> a2 >> b2;
		r2 = (a2 + b2) % k;
		cin1.close();

		if (a1 == a2 && a1 == -1) {
			continue;
		}

		if (r1 != r2 || !in(a, b, a1) || !in(a, b, a2) || !in(c, d, b1) || !in(c, d, b2)) {
			cout << "Wrong Answer!!";
			return 0;
		}
	}
	cout << "Passed!";
	return 0;
}