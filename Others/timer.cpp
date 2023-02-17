#include <iostream>
#include <windows.h>
#include <ctime>
#include <unistd.h>
#include <bits/stdc++.h>
using namespace std;

void xuat() {
    int TIME = clock() / 1000;
    if (TIME < 3600)
        cerr << "00:";
    else {
        if (TIME < 36000)
            cerr << "0";
        cerr << TIME / 3600 << ":";
    }
    TIME -= TIME / 3600 * 3600;
    if (TIME < 60)
        cerr << "00:";
    else {
        if (TIME < 600)
            cerr << "0";
        cerr << TIME / 60 << ":";
    }
    TIME -= TIME / 60 * 60;
    if (TIME < 10)
        cerr << "0";
    cerr << TIME << endl;
    string s;
    ifstream cin("test.out");
    cin >> s;
    cin.close();
    cerr << s << endl;
}

void luu() {
    ofstream cout("test.out");
    int TIME = clock() / 1000;
    if (TIME < 3600)
        cout << "00:";
    else {
        if (TIME < 36000)
            cout << "0";
        cout << TIME / 3600 << ":";
    }
    TIME -= TIME / 3600 * 3600;
    if (TIME < 60)
        cout << "00:";
    else {
        if (TIME < 600)
            cout << "0";
        cout << TIME / 60 << ":";
    }
    TIME -= TIME / 60 * 60;
    if (TIME < 10)
        cout << "0";
    cout << TIME << endl;
    cout.close();
    xuat();
}

int main() {
    ofstream cout("test.out");
    cout.close();
    while (true) {
        system("cls");
        xuat();
        Sleep(50);
        if (GetAsyncKeyState(VK_SPACE) & 0x80000000) {
            luu();
        }
    }
    return 0;
}