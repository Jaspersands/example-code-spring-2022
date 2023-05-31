//Ethan Wu, Jasper Sands -- wue@wustl.edu, jaspersands@wustl.edu -- CSE 332 -- Lab 5
#pragma once
#include "AbstractCommand.h"
#include "AbstractFileSystem.h"
#include "AbstractFileFactory.h"
#include <string>
using namespace std;

class TouchCommand : public AbstractCommand {
private:
	AbstractFileSystem* sys;
	AbstractFileFactory* fac;
public:
	TouchCommand(AbstractFileSystem*, AbstractFileFactory*);
	int execute(string);
	void displayInfo();
};

enum touchOutcomes {
	ssuccess = 0, creationFail = 10, additionFail = 11
};