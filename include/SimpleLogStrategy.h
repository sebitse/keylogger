#ifndef SIMPLELOG_H
#define SIMPLELOG_H

#include "LogStrategy.h"

class SimpleLogStrategy : public LogStrategy
{
    public:
        void log(char key, std::ofstream& logfile) override;
};

#endif // SIMPLELOG_H
