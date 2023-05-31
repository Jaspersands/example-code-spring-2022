//Ethan Wu, Jasper Sands -- wue@wustl.edu, jaspersands@wustl.edu -- CSE 332 -- Lab 5
#pragma once
#include <string>
#include <vector>
#include "AbstractFile.h"
// studio 18 - file factory interface declared here
class AbstractFileFactory {
public:
	virtual AbstractFile* createFile(string) = 0;
private:
	string name;
};
