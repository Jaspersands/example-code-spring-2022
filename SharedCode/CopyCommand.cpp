//Ethan Wu, Jasper Sands -- wue@wustl.edu, jaspersands@wustl.edu -- CSE 332 -- Lab 5
#include "CopyCommand.h"
#include "AbstractFile.h"
#include <iostream>
#include <sstream>

using namespace std;

CopyCommand::CopyCommand(AbstractFileSystem* a) : sys(a) {}

void CopyCommand::displayInfo() {
	cout << "Copy creates a copy of an existing file and adds it to the system. You can invoke the command with: cp <file_to_copy> <new_filename>. The new file name should not have an extension." << endl;
}
//copy file to new file, add extension based on type of file
int CopyCommand::execute(string s) {
	string file;
	string newfile;
	istringstream iss(s);
	if (iss >> file) {
		AbstractFile* temp = sys->openFile(file);
		if (temp == nullptr) {
			cout << "Could not copy file." << endl;
			return copyFail;
		}
		else {
			if (iss >> newfile) {
				AbstractFile* copy = temp->clone(newfile);
				if (sys->addFile(copy->getName(), copy) == sssuccesss) {
					sys->closeFile(temp);
					return sssuccesss;
				}
				else {
					sys->closeFile(temp);
					return copyFail;
				}
				
			}
			else {
				cout << "Could not copy file." << endl;
				sys->closeFile(temp);
				return copyFail;
			}
		}
	}
	else {
		cout << "Could not copy file." << endl;
		return copyFail;
	}
}