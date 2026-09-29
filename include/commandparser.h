#ifndef _COMMANDPARSER_H
#define _COMMANDPARSER_H

#include "universe.h"
#include "command.h"

class CommandParser {
public:
    CommandParser() = default;
    Command* parseCommand(std::string& string);
private:
    bool getWordFromString(int pos, const std::string& s, std::string& out);
};


#endif 
