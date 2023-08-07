#include <stdio.h>
#include <windows.h>

int main() {
    /*
BOOL CreateProcessA(
  [in, optional]      LPCSTR                lpApplicationName,
  [in, out, optional] LPSTR                 lpCommandLine,
  [in, optional]      LPSECURITY_ATTRIBUTES lpProcessAttributes,
  [in, optional]      LPSECURITY_ATTRIBUTES lpThreadAttributes,
  [in]                BOOL                  bInheritHandles,
  [in]                DWORD                 dwCreationFlags,
  [in, optional]      LPVOID                lpEnvironment,
  [in, optional]      LPCSTR                lpCurrentDirectory,
  [in]                LPSTARTUPINFOA        lpStartupInfo,
  [out]               LPPROCESS_INFORMATION lpProcessInformation
);
    */
   STARTUPINFOW si = {0};
   PROCESS_INFORMATION pi = {0};
   CreateProcessW(
        L"C:\\Windows\\notepad.exe",
        NULL,
        NULL,
        NULL,
        0,
        BELOW_NORMAL_PRIORITY_CLASS,
        NULL,
        NULL,
        &si,
        &pi
    );
    printf("(-) process created! id: %ld\n", pi.dwProcessId);

    if (OpenProcess(
        PROCESS_ALL_ACCESS,
        0,
        pi.dwProcessId
    ) == NULL) {
        printf("can't open process.");
    }
    else {
        printf("opened successfully.");
    }
    return EXIT_SUCCESS;
}