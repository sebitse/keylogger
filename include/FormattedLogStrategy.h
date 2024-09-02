#ifndef FORMATTEDLOG_H
#define FORMATTEDLOG_H

#include <sstream>
#include <iomanip>

#include "LogStrategy.h"

class FormattedLogStrategy : public LogStrategy
{
    private:
        std::string format;
        void replacePlaceholders(std::string& str, const std::string& placeholder, const std::string& value);
        std::string formatMessage(const std::string& message);
        std::string currentTime();
    public:
        FormattedLogStrategy(const std::string& format = "[%H:%M:%S] {MESSAGE}");
        void setFormat(const std::string&);
        void log(std::string key, std::ofstream& logfile) override;
};



#endif // FORMATTEDLOG_H
