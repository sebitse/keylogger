#ifndef ENCRYPTEDLOG_H
#define ENCRYPTEDLOG_H

#include "LogStrategy.h"
#include <stdint.h>

class EncryptedLogStrategy : public LogStrategy
{
    private:
        uint8_t shiftAmount; // the shift amount for Caesar cipher
    public:
        // Constructor
        EncryptedLogStrategy(uint8_t shiftAmount);

        // Caesar Encryption implementation
        std::string caesarEncryption(std::string);

        // log implementation
        void log(std::string key, std::ofstream& logfile) override;
};

#endif // ENCRYPTEDLOG_H
