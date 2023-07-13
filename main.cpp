
#include <Windows.h>
#include <iostream>

int main() {
    PROCESS_INFORMATION process_info;
    STARTUPINFO start_info;
    ZeroMemory(&start_info, sizeof(start_info));
    start_info.cb = sizeof(STARTUPINFO);

    if (!CreateProcess(L".\\run.cmd", nullptr, nullptr, nullptr, false, NULL, nullptr, nullptr, &start_info, &process_info)) {
        std::cout << "Execute Failed\n";
        system("PAUSE");
    }
    else {
        CloseHandle(process_info.hProcess);
        CloseHandle(process_info.hThread);
        std::cout << "Execute Succeed\n";
    }
    return 0;
}

