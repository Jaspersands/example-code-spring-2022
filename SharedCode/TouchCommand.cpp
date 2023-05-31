//Ethan Wu, Jasper Sands -- wue@wustl.edu, jaspersands@wustl.edu -- CSE 332 -- Lab 5
#include "TouchCommand.h"
#include <iostream>
#include <sstream>
#include "PasswordProxy.h"


using namespace std;

TouchCommand::TouchCommand(AbstractFileSystem* fs, AbstractFileFactory * ff) : sys(fs), fac(ff) {}

int TouchCommand::execute(string s) {
	string file;
	string p;
	istringstream iss(s);
	if (iss >> file) {
		AbstractFile* af = fac->createFile(file);
		if (af != nullptr) {
			if (iss >> p && p == "-p") {
				cout << "What is the password?" << endl;
				string password;
				getline(cin, password);
				AbstractFile* proxy = new PasswordProxy(af, password);
				if (sys->addFile(file, proxy) == ssuccess) {
					return ssuccess;
				}
				else {
					delete proxy;
					return additionFail;
				}
			}
			else {
				if (sys->addFile(s, af) == ssuccess) {
					return ssuccess;
				}
				else {
					delete af;
					return additionFail;
				}
			}
		}
		else {
			return creationFail;
		}
	
	}
	else {
		return creationFail;
	}
}
void TouchCommand::displayInfo() {
	cout << "Touch creates a file, touch can be invoked with the command: touch <filename> [-p]. (optional: use -p to indicate a password protected file.)" << endl;
}
