#include <iostream>
#include <fstream>
using namespace std;

int main() {
	fstream input;
	input.open("input.txt", ios::in);
	if (input.fail()) {
		cout << "Can't open file!!!";
		return 0;
	}
	while (!input.eof()) {
		int a = 0;
		input >> a;
		cout << a << endl;
	}
	return 0;
}