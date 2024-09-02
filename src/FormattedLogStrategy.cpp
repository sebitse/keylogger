#include "../include/FormattedLogStrategy.h"

// Constructor
FormattedLogStrategy::FormattedLogStrategy(const std::string& _format = "[%H:%M:%S] {MESSAGE}") :
                format(_format) {}

// Setter
void FormattedLogStrategy::setFormat(const std::string& _format) 
{
    this->format = _format;    
}

// Replaces the specified placeholder in the string with the provided value
void FormattedLogStrategy::replacePlaceholders(std::string& str, const std::string& placeholder, const std::string& value)
{
    size_t pos = str.find(placeholder); 

    // if the placeholder is found, replace it
    if (pos != std::string::npos) 
    {
        str.replace(pos, placeholder.length(), value);
    }
}

// Formats the message according to the current format
std::string FormattedLogStrategy::formatMessage(const std::string& message)
{
    std::string aux = this->format; // make a copy

    // perform the modification of that copy
    replacePlaceholders(aux, "{MESSAGE}", message);
    replacePlaceholders(aux, "%H:%M:%S", currentTime());
    
    return aux;
}

// Retrieves the current time as string (HH:MM:SS)
std::string FormattedLogStrategy::currentTime()
{
    std::ostringstream oss;
    auto t = std::time(nullptr);
    auto tm = *std::localtime(&t);
    oss << std::put_time(&tm, "%H:%M:%S"); // Format the current time

    return oss.str();
}

// logs the formatted key/message
void FormattedLogStrategy::log(std::string key, std::ofstream& logfile) 
{
    std::string formattedMessage = formatMessage(key); // Format the key

    logfile << formattedMessage; // write it
    logfile.flush(); 
}
