#ifndef _MODEPARSER_H
#define _MODEPARSER_H


#include "mode.h"
#include "universe.h"

class ModeParser {
public:
    ModeParser() = default;
    Mode* parseMode(int argc, char** argv);
private:
};

#endif 
