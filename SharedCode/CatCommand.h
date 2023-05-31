//Ethan Wu, Jasper Sands -- wue@wustl.edu, jaspersands@wustl.edu -- CSE 332 -- Lab 5
#pragma once
#include "AbstractFile.h"
#include "AbstractCommand.h"
#include "AbstractFileSystem.h"
#include <vector>
#include <string>
using namespace std;


class CatCommand : public AbstractCommand {
public:
	CatCommand(AbstractFileSystem*);
	~CatCommand() = default;
	int execute(string);
	void displayInfo();

private:
	AbstractFileSystem* sys;
};

enum cat {
	ssuuccess = 0, catFail = 65, appendFail = 6
};