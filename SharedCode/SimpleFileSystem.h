//Ethan Wu, Jasper Sands -- wue@wustl.edu, jaspersands@wustl.edu -- CSE 332 -- Lab 5
#pragma once
#include "AbstractFileSystem.h"
#include <map>
#include <set>

class SimpleFileSystem : public AbstractFileSystem {
public: 
	int addFile(string, AbstractFile*);
	int deleteFile(string);
	AbstractFile* openFile(string);
	int closeFile(AbstractFile*);
	std::set<string> getFileNames();
private: 
	map<string, AbstractFile*> files;
	set<AbstractFile*> openFiles;
};

enum outcomes {
	succcess = 0, notOpen = 1, deleteFail = 2, noCreate = 3, noAdd

};
