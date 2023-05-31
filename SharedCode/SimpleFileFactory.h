//Ethan Wu, Jasper Sands -- wue@wustl.edu, jaspersands@wustl.edu -- CSE 332 -- Lab 5
#pragma once
#include "AbstractFileFactory.h"

class SimpleFileFactory : public AbstractFileFactory {
public:
	AbstractFile* createFile(string);
	
};
