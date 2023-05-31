//Ethan Wu, Jasper Sands -- wue@wustl.edu, jaspersands@wustl.edu -- CSE 332 -- Lab 5
// define methods of SimpleFileSystem class here
#include "SimpleFileSystem.h"
using namespace std;
#include <map>
#include <string>
#include "TextFile.h"
#include "ImageFile.h"

int SimpleFileSystem::addFile(string s, AbstractFile* a) {
	if (a == nullptr) {
		return noAdd;
	}
	if (files.find(s) != files.end()) {
		return noAdd;
	}
	files.insert(pair<string, AbstractFile*>(s, a));
	return succcess;
}

int SimpleFileSystem::deleteFile(string s) {
	if (files.find(s) != files.end() && openFiles.find(files[s]) == openFiles.end()) {
		delete files[s];
		files.erase(s);	
		return succcess;
	}
	else {
		return deleteFail;
	}
}
AbstractFile* SimpleFileSystem::openFile(string s) {
	if (files.find(s) != files.end() && openFiles.find(files[s]) == openFiles.end()) {
		openFiles.insert(files[s]);
		return files[s];
	}
	else {
		return nullptr;
	}
}

int SimpleFileSystem::closeFile(AbstractFile* a) {
	set<AbstractFile*>::iterator itr;
	for (itr = openFiles.begin(); itr != openFiles.end(); ++itr) {
		if (a == *itr) {
			openFiles.erase(a);
			return succcess;
		}
	}
	return notOpen;
}


set<string> SimpleFileSystem::getFileNames() {
	map<string, AbstractFile*>::iterator it;
	set<string> names;
	for (it = files.begin(); it != files.end(); ++it) {
		names.insert(it->first);
	}
	return names;
}

