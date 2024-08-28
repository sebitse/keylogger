#include "../include/SimpleLogStrategy.h"

void SimpleLogStrategy::log(char key, std::ofstream& logfile) {
    logfile << key;
    logfile.flush(); // Ensure the key is written immediately
}
