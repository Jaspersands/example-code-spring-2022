// Studio21.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include "../../SharedCode/AbstractFileSystem.h"
#include "../../SharedCode/SimpleFileFactory.h"
#include "../../SharedCode/TextFile.h"
#include "../../SharedCode/ImageFile.h"
#include "../../SharedCode/AbstractFile.h"
#include "../../SharedCode/SimpleFileSystem.h"
#include <iostream>
#include "../../SharedCode/TouchCommand.h"
#include "../../SharedCode/CommandPrompt.h"

int main()
{
	AbstractFileSystem* test = new SimpleFileSystem();
	AbstractFileFactory* fac = new SimpleFileFactory();
	AbstractCommand* tc = new TouchCommand(test, fac);
	CommandPrompt cp;
	string swag = "swag";
	cp.addCommand(swag, tc);
	cp.setFileFactory(fac);
	cp.setFileSystem(test);
	cp.run();

	return 0;
}

