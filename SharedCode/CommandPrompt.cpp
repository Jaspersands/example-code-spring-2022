//Ethan Wu, Jasper Sands -- wue@wustl.edu, jaspersands@wustl.edu -- CSE 332 -- Lab 5
#include "CommandPrompt.h"
#include "AbstractCommand.h"
#include "AbstractFileSystem.h"
#include "AbstractFileFactory.h"
#include "CatCommand.h"
#include "RemoveCommand.h"
#include <iostream>
#include <sstream>
#include <fstream>
#include <string>
#include <map>


using namespace std;

CommandPrompt::CommandPrompt() : system(nullptr), factory(nullptr) {
}

void CommandPrompt::setFileSystem(AbstractFileSystem* as) {
	system = as;
}

void CommandPrompt::setFileFactory(AbstractFileFactory* af) {
	factory = af;
}

int CommandPrompt::addCommand(string s, AbstractCommand* ac) {
	int i = (int)commandMap.size();
	
	commandMap.insert(pair<string, AbstractCommand*>(s, ac));

	if (i != commandMap.size()) {
		return successss;
	}
	else {
		return failureToAdd;
	}
}

void CommandPrompt::listCommands() {
	map<string, AbstractCommand*>::iterator it;
	for (it = commandMap.begin(); it != commandMap.end(); it++) {
		cout << it->first << endl;
	}
}

string CommandPrompt::prompt() {
	cout << "Please either enter a command, <q> to quit, <help> for a list of commands, or <help> followed by a command name for more information about that command." << endl;
	cout << "$   ";
	string temp;
	getline(cin, temp);
	return temp;
}

int CommandPrompt::run() {
	while (1) {
		string temp = prompt();
		if (temp == "q") {
			return userQuit;
		}
		else if (temp == "help") {
			listCommands();
		}
		else if (temp.find(' ') == string::npos) {
			if (commandMap.find(temp) != commandMap.end()) {
				if (commandMap[temp]->execute("") == successss) {
				}
				else {
					cout << "The command failed. Miserably." << endl;
				}
			}
			else {
				cout << "There is no command with this name." << endl;
			}
		}
		else if (temp.find(' ') != string::npos) {
			string word1;
			string word2;
			istringstream input(temp);
			input >> word1;
			if (word1 == "help") {
				input >> word2;
				if (commandMap.find(word2) != commandMap.end()) {
					commandMap[word2]->displayInfo();
				}
				else {
					cout << "There is no command with this name." << endl;
				}
			}
			else {
				if (commandMap.find(word1) != commandMap.end()) {
					word2 = temp.substr(word1.size() + 1);
					if (commandMap[word1]->execute(word2) == successss) {
					}
					else {
						cout << "The command failed. Miserably." << endl;
					}
				}
				else {
					cout << "There is no command with this name." << endl;
				}
			}

		}
	}

}

