//Ethan Wu, Jasper Sands -- wue@wustl.edu, jaspersands@wustl.edu -- CSE 332 -- Lab 5
#pragma once
#include "AbstractCommand.h"
#include "AbstractFileSystem.h"
#include <string>

using namespace std;

class LSCommand : public AbstractCommand {
private:
	AbstractFileSystem* sys;
public:
	LSCommand(AbstractFileSystem*);
	~LSCommand() = default;
	int execute(string);
	void displayInfo();
};

enum ls {
	exito = 0, smallword = 8, bigword = 16, lsFail = 66
};
