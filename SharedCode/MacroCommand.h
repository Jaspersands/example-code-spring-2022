//Ethan Wu, Jasper Sands -- wue@wustl.edu, jaspersands@wustl.edu -- CSE 332 -- Lab 5
#pragma once
#include "AbstractCommand.h"
#include "AbstractFileSystem.h"
#include <string>
#include <vector>
#include "AbstractParsingStrategy.h"

using namespace std;

class MacroCommand : public AbstractCommand {
private:
	AbstractParsingStrategy* strat;
	vector<AbstractCommand*> commands;
	AbstractFileSystem* sys;
public:
	MacroCommand(AbstractFileSystem*); 
	~MacroCommand() = default;
	int execute(string);
	void displayInfo();
	int addCommand(AbstractCommand*); 
	void setParseStrategy(AbstractParsingStrategy*);
};

enum macro {
	succeess = 0, macroFail = 71
};

