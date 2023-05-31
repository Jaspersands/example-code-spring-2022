//Ethan Wu, Jasper Sands -- wue@wustl.edu, jaspersands@wustl.edu -- CSE 332 -- Lab 5
#pragma once
#include "AbstractFile.h"
#include "AbstractCommand.h"
#include "AbstractFileSystem.h"
#include <string>
using namespace std;


class RemoveCommand : public AbstractCommand {
private:
	AbstractFileSystem* sys;
public:
	RemoveCommand(AbstractFileSystem*);
	~RemoveCommand() = default;
	int execute(string);
	void displayInfo();
};

enum remove {
	successful = 0, removeFail = 50
};