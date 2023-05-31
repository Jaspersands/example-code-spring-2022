//Ethan Wu, Jasper Sands -- wue@wustl.edu, jaspersands@wustl.edu -- CSE 332 -- Lab 5
#pragma once
#include "../../SharedCode/AbstractFile.h"
#include "../../SharedCode/AbstractCommand.h"
#include "../../SharedCode/AbstractFileSystem.h"
#include <vector>
#include <string>

using namespace std;

class chmodCommand : public AbstractCommand {
private:
	AbstractFileSystem* sys;
public:
	chmodCommand(AbstractFileSystem*);
	~chmodCommand() = default;
	int execute(string);
	void displayInfo();
};

enum chmodO {
	successfulchmod = 0, chmodFail = 97
};