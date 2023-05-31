//Ethan Wu, Jasper Sands -- wue@wustl.edu, jaspersands@wustl.edu -- CSE 332 -- Lab 5
#pragma once
#include <string>
#include <vector>
#include <set>
#include "AbstractFile.h"
using namespace std;

class AbstractFileSystem {
public: 
	virtual int addFile(string, AbstractFile*) = 0;
	virtual int deleteFile(string) = 0;
	virtual AbstractFile* openFile(string) = 0;
	virtual int closeFile(AbstractFile*) = 0;
	virtual std::set<string> getFileNames() = 0;
};
