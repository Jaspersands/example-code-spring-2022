//Ethan Wu, Jasper Sands -- wue@wustl.edu, jaspersands@wustl.edu -- CSE 332 -- Lab 5
#include "LSCommand.h"
#include "SimpleFileSystem.h"
#include <iostream>
#include <string>
#include <sstream>
#include "MetadataDisplayVisitor.h"


using namespace std;

LSCommand::LSCommand(AbstractFileSystem* a) : sys(a) {}

void LSCommand::displayInfo() {
	cout << "LS displays the names of all files currently in the file system. You can use it with the command: ls [-m]. (optional: use -m to also display metadata)." << endl;
}

//display all files, 2 files per line
//if -m, display 1 file per line as well as type of file and size
int LSCommand::execute(string s) {
	set<string> allFiles = sys->getFileNames();
	string m;
	istringstream iss(s);
	if (iss >> m && m == "-m") {
		MetadataDisplayVisitor meta;
		set<string>::iterator itr;
		for (itr = allFiles.begin(); itr != allFiles.end(); ++itr) {
			AbstractFile* temp = sys->openFile(*itr);
			temp->accept(&meta);  
			sys->closeFile(temp);
		}
		return exito;
	}
	else {
		bool column = true;
		set<string>::iterator it;
		for (it = allFiles.begin(); it != allFiles.end(); ++it) {
			if (column == true) {
				if ((*it).size() < smallword) {
					cout << *it << "\t\t\t";
				}
				else if ((*it).size() >= smallword && (*it).size() < bigword) {
					cout << *it << "\t\t";
				}
				else {
					cout << *it << "\t";
				}
				column = false;
			}
			else {
				cout << *it << endl;
				column = true;
			}
		}
		if (column == false) {
			cout << endl;
		}
		return exito;
	}
}
