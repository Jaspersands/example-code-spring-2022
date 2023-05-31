// Studio18.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include "../../SharedCode/AbstractFileSystem.h"
#include "../../SharedCode/SimpleFileFactory.h"
#include "../../SharedCode/TextFile.h"
#include "../../SharedCode/ImageFile.h"
#include "../../SharedCode/AbstractFile.h"
#include "../../SharedCode/SimpleFileSystem.h"
#include <iostream>

using namespace std;

int main()
{
	AbstractFileSystem* test = new SimpleFileSystem();
	AbstractFileFactory* fac = new SimpleFileFactory();
	AbstractFile* a = fac->createFile("filename");
	AbstractFile* t = fac->createFile("text.txt");
	AbstractFile* i = fac->createFile("image.img");
	cout << t->getSize() << endl;
	cout << t->getName() << endl;
	
	test->addFile("text", t);
	test->addFile("image", t);
	cout << test->addFile("ThisShouldn'tWork", a) << endl;
	cout << test->openFile("ThisShouldn'tWork") << endl;
	cout << test->openFile("text.txt") << endl;
	cout << test->openFile("text") << endl;
	cout << test->deleteFile("text") << endl;
	cout << test->closeFile(t) << endl;
	cout << test->deleteFile("text") << endl;

	vector<char> v = { 'X', 'X', ' ', ' ', '2'}; //this kinda doesn't work fam
		i->write(v);
		i->read();
		cout << i->getName() << endl;
		cout << i->getSize() << endl;

	//do/cout the image methods here
	return 0;
}
