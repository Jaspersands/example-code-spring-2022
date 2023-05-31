//Ethan Wu, Jasper Sands -- wue@wustl.edu, jaspersands@wustl.edu -- CSE 332 -- Lab 5
#include "DisplayCommand.h"
#include "BasicDisplayVisitor.h"
#include "SimpleFileSystem.h"
#include <vector>
#include <string>
#include <iostream>
#include <sstream>


using namespace std;

DisplayCommand::DisplayCommand(AbstractFileSystem* a) : sys(a) {}

void DisplayCommand::displayInfo() {
	cout << "'Display' opens a file and displays its contents. You can use this with the command: ds <filename> [-d]. (optional: use -d to indicate an unformatted display)" << endl;
}
//if -d, display unformatted with read, else display formatted file with visitor
int DisplayCommand::execute(string s) {
	string file;
	string option;
	istringstream iss(s);
		if (iss >> file) {
			AbstractFile* temp = sys->openFile(file);
			if (temp == nullptr) {
				return displayFail;
			}
			else {
				if (iss >> option && option == "-d") {
					for (int i = 0; i < temp->read().size(); ++i) {
						cout << temp->read()[i];
					}
					cout << endl;
					sys->closeFile(temp);
					return ssssuccess;
				}
				else {
					BasicDisplayVisitor* visitor = new BasicDisplayVisitor;
					temp->accept(visitor);
					delete visitor;
					sys->closeFile(temp);
					return ssssuccess;
				}
			}		
		}
		else {
			return displayFail;
		}
}
