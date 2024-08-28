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
        char caesarEncryption(char);

        // log implementation
        void log(char key, std::ofstream& logfile) override;
};

#endif // ENCRYPTEDLOG_H
