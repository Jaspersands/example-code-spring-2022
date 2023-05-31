//Ethan Wu, Jasper Sands -- wue@wustl.edu, jaspersands@wustl.edu -- CSE 332 -- Lab 5
#include "RemoveCommand.h"
#include "SimpleFileSystem.h"
#include <vector>
#include <string>
#include <iostream>
#include <sstream>
#include "TextFile.h"
#include "ImageFile.h"


using namespace std;

RemoveCommand::RemoveCommand(AbstractFileSystem* a) : sys(a) {}

void RemoveCommand::displayInfo() {
	cout << "Remove removes a file from the file system given a file name. You can use it with the command: rm <filename>" << endl;
}

//delete a given file
int RemoveCommand::execute(string s) {
	string file;
	istringstream iss(s); 
	if (iss >> file) {
		if (sys->deleteFile(file) == successful) {
			return successful;
		}
		else {
			return removeFail;
		}
	}
	else {
		return removeFail;
	}


}

