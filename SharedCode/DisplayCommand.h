//Ethan Wu, Jasper Sands -- wue@wustl.edu, jaspersands@wustl.edu -- CSE 332 -- Lab 5
#pragma once
#include "AbstractFile.h"
#include "AbstractCommand.h"
#include "AbstractFileSystem.h"
#include <string>

class DisplayCommand : public AbstractCommand {

public:
	DisplayCommand(AbstractFileSystem*);
	~DisplayCommand() = default;
	int execute(string);
	void displayInfo();

private:
	AbstractFileSystem* sys;
};

enum dis {
	ssssuccess = 0, displayFail = 64
};