#include <windows.h>
using namespace std;

int main() {
    MessageBoxW(
        NULL,
        L"Hello World!",
        L"Title here",
        MB_YESNOCANCEL | MB_ICONQUESTION
    );
    return EXIT_SUCCESS;
}