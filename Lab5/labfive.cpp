// labfive.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "SimpleFileSystem.h"
#include "SimpleFileFactory.h"
#include<algorithm>
#include<iterator>
#include "ReadFileVisitor.h"
#include "HierarchicalFileSystem.h"
#include "HierarchicalFileFactory.h"
#include "CommandPrompt.h"
#include "TouchCommand.h"
#include "CDCommand.h"
#include "LSCommand.h"
#include "RemoveCommand.h"
#include "ImageFile.h"
#include "TextFile.h"
#include "DisplayCommand.h"
#include "CatCommand.h"
#include "CopyCommand.h"
#include "SymbolicLinkCommand.h"

using namespace std;

int main(int argc, char* arg[])
{
	// allocate all objects needed
	AbstractFileFactory* ff = new HierarchicalFileFactory();
	AbstractFileSystem* fs = new HierarchicalFileSystem();

	AbstractCommand* com = new TouchCommand(ff, fs);
	AbstractCommand* com1 = new CDCommand(fs);
	AbstractCommand* com2 = new LSCommand(fs);
	AbstractCommand* com3 = new RemoveCommand(fs);
	AbstractCommand* com4 = new DisplayCommand(fs);
	AbstractCommand* com5 = new CatCommand(fs);
	AbstractCommand* com6 = new CopyCommand(fs);
	AbstractCommand* com7 = new SymbolicLinkCommand(fs);

	AbstractFile* t = new TextFile("t.txt");
	vector<char> x = { 'h', 'o' };
	t->write(x);
	//cout << t->getSize();
	//cout << t->getName();
	fs->addFile("root/t.txt", t);
	AbstractFile* i = new ImageFile("i.img");
	vector<char> s = { 'X', ' ', 'X', ' ', 'X', ' ', 'X',' ', 'X', '3' };
	i->write(s);
	fs->addFile("root/i.img", i);
	AbstractFile* d = new DirectoryFile("dir");
	fs->addFile("root/dir", d);
	AbstractFile* im = new ImageFile("im.img");
	AbstractFile* te = new TextFile("te.txt");
	vector<char> xz = { 'h', 'o' };
	te->write(xz);
	fs->addFile("root/dir/im.img", im);
	fs->addFile("root/dir/te.txt", te);
	fs->openFile("root/dir/te.txt");
	//AbstractFileSystem* dir = new HierarchicalFileSystem;
	//fs->addFile("root/dir/t.txt", t);

	// create command prompt and configure
	// NOTE: the above commands will not work with a SimpleFileSystem, it would need a new set of commands
	// or a second CommandPrompt class
	CommandPrompt cmd;
	cmd.setFileSystem(fs);
	cmd.setFileFactory(ff);
	cmd.addCommand("touch", com);
	cmd.addCommand("cd", com1);
	cmd.addCommand("ls", com2);
	cmd.addCommand("rm", com3);
	cmd.addCommand("ds", com4);
	cmd.addCommand("cat", com5);
	cmd.addCommand("cp", com6);
	cmd.addCommand("sym", com7);

	// run the command prompt
	cmd.run();

	// clean up dynamically allocated resources
	delete ff;
	delete fs; // all files are destroyed here (in the file system destructor)
	delete com;
	delete com1;
	delete com2;
	delete com3;
	delete com4;
	delete com5;
	delete com6;
	delete com7;

	return 0;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
