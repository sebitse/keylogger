#ifndef FORMATTEDLOG_H
#define FORMATTEDLOG_H

#include <sstream>
#include <iomanip>

#include "LogStrategy.h"

// This class provides a logging strategy that formats log messages 
class FormattedLogStrategy : public LogStrategy
{
    private:
        std::string format; // The format string used to format log messages

        // Replaces placeholders in the format string 
        void replacePlaceholders(std::string& str, const std::string& placeholder, const std::string& value);

        // Formats the message based on the current format string
        std::string formatMessage(const std::string& message);

        // Retrieves the current time (HH:MM:SS) 
        std::string currentTime();

    public:
        // Constructor
        FormattedLogStrategy(const std::string& format = "[%H:%M:%S] {MESSAGE}");

        // Setter for a new possible format
        void setFormat(const std::string&);

        // Logs a formatted message to the provided logfile
        void log(std::string key, std::ofstream& logfile) override;
};

#endif // FORMATTEDLOG_H
