//Ethan Wu, Jasper Sands -- wue@wustl.edu, jaspersands@wustl.edu -- CSE 332 -- Lab 5
#pragma once
#include "AbstractCommand.h"
#include "AbstractFileSystem.h"
#include "AbstractFileFactory.h"
#include <string>

using namespace std;

class CopyCommand : public AbstractCommand {
private:
	AbstractFileSystem* sys;
public:
	CopyCommand(AbstractFileSystem*);
	~CopyCommand() = default;
	int execute(string);
	void displayInfo();
};

enum copy {
	sssuccesss = 0, copyFail = 61
};