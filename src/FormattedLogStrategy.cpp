#include "../include/FormattedLogStrategy.h"

 FormattedLogStrategy::FormattedLogStrategy(const std::string& _format = "[%H:%M:%S] {MESSAGE}") :
                format(_format) {}

void FormattedLogStrategy::setFormat(const std::string& _format) 
{
    this->format = _format;    
}

void FormattedLogStrategy::replacePlaceholders(std::string& str, const std::string& placeholder, const std::string& value)
{
    size_t pos = str.find(placeholder);

    if (pos != std::string::npos) 
    {
        str.replace(pos, placeholder.length(), value);
    }
}
std::string FormattedLogStrategy::formatMessage(const std::string& message)
{
    std::string aux = this->format;

    replacePlaceholders(aux, "{MESSAGE}", message);
    replacePlaceholders(aux, "%H:%M:%S", currentTime());
    
    return aux;
}

std::string FormattedLogStrategy::currentTime()
{
    std::ostringstream oss;
    auto t = std::time(nullptr);
    auto tm = *std::localtime(&t);
    oss << std::put_time(&tm, "%H:%M:%S");

    return oss.str();
}

void FormattedLogStrategy::log(std::string key, std::ofstream& logfile) 
{
    std::string formattedMessage = formatMessage(key);

    logfile << formattedMessage;
    logfile.flush();
}
