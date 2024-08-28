
#ifdef _WIN32

#include "../include/KeyLogger.h"
#include <iostream>

KeyLogger::KeyLogger() : 
        logStrategy(nullptr),
        running(false) {}

KeyLogger::~KeyLogger() 
{
    delete logStrategy;

    if(this->isRunning())
    {
        running=false;
    }
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

void KeyLogger::start()
{
    running = true;
    char key;

    while(running)
    {
        // need to think
    }
}

void KeyLogger::stop()
{
    if(this->isRunning())
    {
        running=false;
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
