#ifndef FORMATTEDLOG_H
#define FORMATTEDLOG_H

#include "LogStrategy.h"

class FormattedLogStrategy : public LogStrategy
{
    public:
        void log(std::string key, std::ofstream& logfile) override;
};



#endif // FORMATTEDLOG_H
