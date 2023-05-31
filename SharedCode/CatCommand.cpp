//Ethan Wu, Jasper Sands -- wue@wustl.edu, jaspersands@wustl.edu -- CSE 332 -- Lab 5
#include "CatCommand.h"
#include <vector>
#include <string>
#include <iostream>
#include <sstream>
#include <fstream>
#include "TextFile.h"
#include "ImageFile.h"
#include "SimpleFileSystem.h"

using namespace std;

CatCommand::CatCommand(AbstractFileSystem* a) : sys(a) {}

void CatCommand::displayInfo() {
	cout << "The cat function gives the user the option to write to or append to a file. You can use this with the command: cat <filename> [-a]. Typing “-a” after “cat <filename>” will print the unformatted file and prompt the user to write something they want to append. The user is also given the option to type “:wq” to save and quit which will append what they’ve wrote or “:q” which will quit without appending what they wrote. If there is no “-a” after the file name, the input will overwrite the existing file instead of append and the file will not be printed beforehand." << endl;
}
//if -a, print unformatted and append, else overwrite file
//keep entering text until :q (quit) or :wq (save and quit)
int CatCommand::execute(string s) {
	string file;
	string option;
	istringstream iss(s);
	if (iss >> file) {
		AbstractFile* temp = sys->openFile(file);
		if (temp == nullptr) {
			return catFail;
		}
		else {
			iss >> option;
			if (option == "-a") {
				for (int i = 0; i < temp->read().size(); ++i) {
					cout << temp->read()[i];
				}
				cout << endl;
				cout << "Enter data you would like to append to the file. Enter :wq to save the file and exit. Enter :q to exit without saving" << endl;
			}
			else {
				cout << "Enter data you would like to write to the file. Enter :wq to save the file and exit. Enter :q to exit without saving" << endl;
			}
			bool w = true;
			vector<char> v;
			while (w) {
				string line;
				getline(cin, line);
				if (line == ":q") {
					sys->closeFile(temp);
					return ssuuccess;
				}
				else if (line == ":wq" && option == "-a") {
					v.pop_back();
					if (temp->append(v) == ssuuccess) {
						sys->closeFile(temp);
						return ssuuccess;
					}
					sys->closeFile(temp);
					return catFail;
				}
				else if (line == ":wq") {
					v.pop_back();
					if (temp->write(v) == ssuuccess) {
						sys->closeFile(temp);
						return ssuuccess;
					}
					sys->closeFile(temp);
					return catFail;
				}
				else {
					for (char i : line) {
						v.push_back(i);
					}
					v.push_back('\n');
				}
			}
			sys->closeFile(temp);
			return catFail;
		}
	}
	else {
		return catFail;
	}

}