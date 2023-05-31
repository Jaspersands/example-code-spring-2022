//Ethan Wu, Jasper Sands -- wue@wustl.edu, jaspersands@wustl.edu -- CSE 332 -- Lab 5
#include "../../SharedCode/SimpleFileFactory.h"
#include "../../SharedCode/SimpleFileSystem.h"
#include "../../SharedCode/ImageFile.h"
#include "../../SharedCode/TextFile.h"
#include "../../SharedCode/CommandPrompt.h"
#include "../../SharedCode/CatCommand.h"
#include "../../SharedCode/AbstractCommand.h"
#include "../../SharedCode/TouchCommand.h"
#include "../../SharedCode/CopyCommand.h"
#include "../../SharedCode/DisplayCommand.h"
#include "../../SharedCode/LSCommand.h"
#include "../../SharedCode/MacroCommand.h"
#include "../../SharedCode/RemoveCommand.h"
#include "../../SharedCode/RenameParsingStrategy.h"
#include "TouchCatParsingStrategy.h"
#include "chmodCommand.h"

int main()
{
	//make base
	AbstractFileFactory* factory = new SimpleFileFactory;
	AbstractFileSystem* system = new SimpleFileSystem;
	
	//make commands
	AbstractCommand* Touch = new TouchCommand(system, factory);
	AbstractCommand* LS = new LSCommand(system);
	AbstractCommand* Remove = new RemoveCommand(system);
	AbstractCommand* Copy = new CopyCommand(system);
	AbstractCommand* Display = new DisplayCommand(system);
	AbstractCommand* Cat = new CatCommand(system);
	AbstractCommand* ChMod = new chmodCommand(system);
	MacroCommand* RenameMacro = new MacroCommand(system);
	MacroCommand* TouchCatMacro = new MacroCommand(system);

	//make parsing strategies
	AbstractParsingStrategy* Rename = new RenameParsingStrategy();
	AbstractParsingStrategy* TouchCat = new TouchCatParsingStrategy();

	//configure macros
	RenameMacro->addCommand(Copy);
	RenameMacro->addCommand(Remove);
	RenameMacro->setParseStrategy(Rename);
	TouchCatMacro->addCommand(Touch);
	TouchCatMacro->addCommand(Cat);
	TouchCatMacro->setParseStrategy(TouchCat);

	//make and configure command prompt
	CommandPrompt cp;
	cp.addCommand("touch", Touch);
	cp.addCommand("ls", LS);
	cp.addCommand("rm", Remove);
	cp.addCommand("ds", Display);
	cp.addCommand("cp", Copy);
	cp.addCommand("cat", Cat);
	cp.addCommand("macro", RenameMacro);
	cp.addCommand("tcmacro", TouchCatMacro);
	cp.setFileFactory(factory);
	cp.setFileSystem(system);
	cp.run();

	delete factory;
	delete system;
	delete Touch;
	delete LS;
	delete Remove;
	delete Display;
	delete Cat;
	delete Copy;
	delete RenameMacro;
	delete TouchCatMacro;
	delete Rename;
	delete TouchCat;
	delete ChMod;

	return 0;
}


