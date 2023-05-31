//Ethan Wu--wue@wustl.edu // Jasper Sands--jaspersands@wustl.edu // CSE 332 Lab 5
#include "MacroCommand.h"
#include <iostream>
#include <sstream>

using namespace std;

MacroCommand::MacroCommand(AbstractFileSystem* a) : strat(nullptr), commands({}), sys(a) {}

void MacroCommand::displayInfo() {
	cout << "A macro command is a command made up of multiple commands." << endl;
}

int MacroCommand::execute(string s) {
	vector<string> commandList = strat->parse(s);
	for (int i = 0; i < commands.size(); ++i) {
		if (commands[i]->execute(commandList[i]) != succeess) {
			return macroFail;
		}
	}
	return succeess;
}

int MacroCommand::addCommand(AbstractCommand* ac) {
	int i = (int)commands.size();
	commands.push_back(ac);
	if (i != commands.size()) {
		return succeess;
	}
	else {
		return macroFail;
	}
}

void MacroCommand::setParseStrategy(AbstractParsingStrategy* aps) {
	strat = aps;
}