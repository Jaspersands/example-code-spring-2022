// Studio19.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include "../../SharedCode/AbstractFileSystem.h"
#include "../../SharedCode/SimpleFileFactory.h"
#include "../../SharedCode/TextFile.h"
#include "../../SharedCode/ImageFile.h"
#include "../../SharedCode/AbstractFile.h"
#include "../../SharedCode/SimpleFileSystem.h"
#include "../../SharedCode/BasicDisplayVisitor.h"
#include "../../SharedCode/AbstractFileVisitor.h"

using namespace std;

int main()
{
	AbstractFileSystem* test = new SimpleFileSystem();
	AbstractFileFactory* fac = new SimpleFileFactory();
	AbstractFile* t = fac->createFile("text.txt");
	AbstractFile* i = fac->createFile("image.img");

	BasicDisplayVisitor* dis;

	return 0;
}
