#include <iostream>
#include <ctime>
#include <iomanip>
#include <vector>
#include <bits/stdc++.h>
#include <stdexcept> // std::runtime_error
#include <stdio.h>
#include <conio.h>
#include <Windows.h>

#ifdef _WIN32
    #include <windows.h>
    #define CLEAR "cls"
#else
    #include <unistd.h>
    #define CLEAR "clear"
#endif

using namespace std;

class MaxEnterException : public runtime_error {
public:
    MaxEnterException(const string& message) : runtime_error(message) {}
};

void print_time(time_t elapsed) {
    int hours = elapsed / 3600;
    int minutes = (elapsed % 3600) / 60;
    int seconds = elapsed % 60;

    cout << setfill('0') << setw(2) << hours << ":"
         << setfill('0') << setw(2) << minutes << ":"
         << setfill('0') << setw(2) << seconds << endl;
}

int main() {
    vector<time_t> timelapses;
    time_t start_time = time(0);
    int enter_count = 0;
    const int max_enters = 5;
    char input;

    cout << "00:00:00" << endl;

    try {
        while (true) {
            Sleep(50);
            if (kbhit()) {
                input = cin.get();
                if (input == '\n') { // Enter key
                    enter_count++;
                    if (enter_count > max_enters) {
                        throw MaxEnterException("Qua 5 lan");
                    }
                    system(CLEAR); // Clear the console screen
                    time_t now = time(0);
                    time_t elapsed = now - start_time;
                    timelapses.push_back(elapsed); 
                    cout << "Timelapse " << enter_count << ": ";
                    print_time(elapsed);
                } else if (input == ' ') { // Space key
                    cout << "Dung dong ho." << endl;
                    break;
                }
            }
            else {
                system(CLEAR); // Clear the console screen
                time_t now = time(0);
                time_t elapsed = now - start_time;
                cout << "Timelapse " << enter_count << ": ";
                print_time(elapsed);
            }
        }
    } catch (const MaxEnterException& e) {
        cout << e.what() << endl;
    }

    cout << "All timelapses:" << endl;
    for (size_t i = 0; i < timelapses.size(); ++i) {
        cout << "Timelapse " << i + 1 << ": ";
        print_time(timelapses[i]);
    }

    return 0;
}
