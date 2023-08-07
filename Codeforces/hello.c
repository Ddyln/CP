#include <windows.h>

int main() {
    MessageBoxW(
        NULL,
        L"Hello World!",
        L"Title here",
        MB_YESNOCANCEL | MB_ICONQUESTION
    );
    int a = 4;
    Sleep(20000);
    return EXIT_SUCCESS;
}