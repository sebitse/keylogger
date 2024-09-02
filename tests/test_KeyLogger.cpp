#include <cassert>
#include <iostream>
#include <sstream>
#include "../include/KeyLogger.h"
#include "../include/SimpleLogStrategy.h"

// Mock test utility class to capture log output in memory
class TestLogStrategy : public LogStrategy 
{
public:
    std::ostringstream logStream;

    void log(std::string key, std::ofstream &logfile) override 
    {
        logStream << key;
    }

    std::string getLoggedData() 
    {
        return logStream.str();
    }
};

void test_LogSpecialKey() 
{
    KeyLogger logger;
    TestLogStrategy testStrategy;
    logger.setLogStrategy(&testStrategy);

    // Simulate pressing the BACKSPACE key (using its virtual key code)
    logger.logKey(static_cast<char>(VK_BACK));

    // Verify the output
    assert(testStrategy.getLoggedData() == "[BACKSPACE]");
}

void test_LogRegularKey() 
{
    KeyLogger logger;
    TestLogStrategy testStrategy;
    logger.setLogStrategy(&testStrategy);

    // Simulate pressing the 'A' key
    logger.logKey('A');

    // Verify the output
    assert(testStrategy.getLoggedData() == "A");
}

int main() 
{
    test_LogSpecialKey();
    test_LogRegularKey();

    std::cout << "All tests passed!" << std::endl;
    return 0;
}
