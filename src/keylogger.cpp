
#ifdef _WIN32

#include "../include/KeyLogger.h"
#include <iostream>

KeyLogger::KeyLogger() : 
        logStrategy(nullptr),
        running(false) {}

KeyLogger::~KeyLogger() 
{
    running = false;
    delete logStrategy;

    if (logfile.is_open())
    {
        logfile.close();
    }
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



#endif
