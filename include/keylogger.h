#ifndef FRIENDLY_KEYLOGGER
#define FRIENDLY_KEYLOGGER

#ifdef _WIN32

#include <windows.h>
#include <fstream>
#include <string>
#include "LogStrategy.h"

#define IS_PRESSED -32767 // -((2^15) - 1) 
#define START_KEY 8 // ascii code for backspace
#define END_KEY 237 // some greek letter
#define RELEVANT_INTERVAL_OF_KEYS (START_KEY END_KEY)
#define PAUSE 10

class KeyLogger {
    private:
        LogStrategy* logStrategy;  // Pointer to the logging strategy
        std::ofstream logfile;     // Output file stream for logging
        bool running;              // Flag to indicate if the keylogger is on

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
