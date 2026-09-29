#ifndef _COMMAND_H
#define _COMMAND_H

#include "rule.h"
#include "universe.h"

#include <string>

class Command {
public:
    virtual void execute(Universe& universe, Rule& rule) = 0;
};

class DumpCommand : public Command{
public:
    DumpCommand(std::string& dumpPath);
    void execute(Universe& universe, Rule& rule) override;
private:
    std::string dumpPath;
};

class TickCommand : public Command{
public:
    TickCommand(int numOfTicks);
    void execute(Universe& universe, Rule& rule) override;
    int getNumOfTicks();
private:
    int numOfTicks;
};

class HelpCommand : public Command{
public:
    HelpCommand() = default;
    void execute(Universe& universe, Rule& rule) override;
private:
};

class ExitCommand : public Command{
public:
    ExitCommand() = default;
    void execute(Universe& universe, Rule& rule) override;
private:
};

class ErrorCommand : public Command{
public:
    ErrorCommand(const std::string& errorMessage);
    void execute(Universe& universe, Rule& rule) override;
private:
};

#endif 
