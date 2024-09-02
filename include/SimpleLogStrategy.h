#ifndef SIMPLELOG_H
#define SIMPLELOG_H

#include "LogStrategy.h"

class SimpleLogStrategy : public LogStrategy
{
    public:
        void log(std::string key, std::ofstream& logfile) override;
};

#endif // SIMPLELOG_H
