//Ethan Wu, Jasper Sands -- wue@wustl.edu, jaspersands@wustl.edu -- CSE 332 -- Lab 5
#pragma once
#include <map>
#include "AbstractCommand.h"
#include "AbstractFileSystem.h"
#include "AbstractFileFactory.h"

using namespace std;


class CommandPrompt {
public:
	CommandPrompt();
	void setFileSystem(AbstractFileSystem*);
	void setFileFactory(AbstractFileFactory*);
	int addCommand(string, AbstractCommand*);
	int run();
private:
	map<string, AbstractCommand*> commandMap;
	AbstractFileSystem* system;
	AbstractFileFactory* factory;
protected:
	void listCommands();
	string prompt();
};

enum cpOutcomes {
	successss = 0, failureToAdd = 21, userQuit = 22
};

