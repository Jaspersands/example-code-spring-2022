// Studio20.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "../../SharedCode/AbstractFileSystem.h"
#include "../../SharedCode/SimpleFileFactory.h"
#include "../../SharedCode/TextFile.h"
#include "../../SharedCode/ImageFile.h"
#include "../../SharedCode/AbstractFile.h"
#include "../../SharedCode/SimpleFileSystem.h"
#include "../../SharedCode/BasicDisplayVisitor.h"
#include "../../SharedCode/AbstractFileVisitor.h"
#include "../../SharedCode/PasswordProxy.h"
#include <iostream>

int main()
{
	
	AbstractFileFactory* fac = new SimpleFileFactory();
	AbstractFile* t = fac->createFile("text.txt");
	PasswordProxy* p = new PasswordProxy(t, "swag");
	AbstractFileVisitor* a = new BasicDisplayVisitor;
	cout << p->getName() << endl;
	cout << p->getSize() << endl;
	vector<char> v = { 'V', 'E', 'R', 'S', 'A', 'C', 'E', '2'};
	vector<char> b = { 'B', 'E', 'R', 'S', 'A', 'C', 'E'};
	p->write(v);
	cout << p->getSize() << endl;
	p->append(b);
	p->accept(a);
	cout << p->getSize() << endl;
	return 0;
}

