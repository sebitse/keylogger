#ifndef LOGSTRATEGY_H
#define LOGSTRATEGY_H

#include <fstream>
#include <string.h>

class LogStrategy {
public:
    // Virtual destructor to ensure cleanup of derived classes
    virtual ~LogStrategy() = default;

    // Pure virtual function that must be implemented by all strategies
    virtual void log(std::string key, std::ofstream& logfile) = 0;
};

#endif 
