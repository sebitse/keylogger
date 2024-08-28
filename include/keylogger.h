#ifndef FRIENDLY_KEYLOGGER
#define FRIENDLY_KEYLOGGER

#ifdef _WIN32

#include <windows.h>
#include <fstream>
#include <string>
#include "LogStrategy.h"

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

        // Starts the keylogger loop
        void start();

        // Stops the keylogger loop
        void stop();

        // Returns whether the keylogger is currently running
        bool isRunning() const;
};

#endif // _WIN32

#endif // FRIENDLY_KEYLOGGER
