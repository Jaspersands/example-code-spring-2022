//Ethan Wu, Jasper Sands -- wue@wustl.edu, jaspersands@wustl.edu -- CSE 332 -- Lab 5
#include "chmodCommand.h"
#include <vector>
#include <string>
#include <iostream>
#include <sstream>
#include <fstream>
#include "../../SharedCode/TextFile.h"
#include "../../SharedCode/ImageFile.h"
#include "../../SharedCode/SimpleFileSystem.h"

using namespace std;

chmodCommand::chmodCommand(AbstractFileSystem* a) : sys(a) {}

void chmodCommand::displayInfo() {
	cout << "chmod makes files read and write only. To invoke this, use the command: chmod <filename> [-/+]. The [-/+] indicates that you either use - to make it read only, or + to make it writeable again." << endl;
}

int chmodCommand::execute(string s) {
	string file;
	string option;
	istringstream iss(s);
	if (iss >> file) {
		AbstractFile* temp = sys->openFile(file);
		if (temp == nullptr) {
			return chmodFail;
		}
		else {
			iss >> option;
			if (option == "-" || option == "+") {
				temp->chmodchange(option);
				sys->closeFile(temp);
				return succcess;
			}
		}
	}
	return chmodFail;
}