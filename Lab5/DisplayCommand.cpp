#include "DisplayCommand.h"
#include "ReadFileVisitor.h"
#include<iostream>

using namespace std;
DisplayCommand::DisplayCommand(AbstractFileSystem* fileSys) : fs(fileSys) {}

int DisplayCommand::execute(string& CWD, string options) {
	vector<string> vs;
	string::size_type pos = 0;
	string::size_type prev = 0;
	while ((pos = options.find(' ', prev)) != std::string::npos) {
		vs.push_back(options.substr(prev, pos - prev));
		prev = pos + 1;
	}
	vs.push_back(options.substr(prev));
	if (vs.size() == 1) {
		string fullPath = CWD;
		fullPath += '/';
		fullPath += options;
		AbstractFile* f = fs->openFile(fullPath);
		if (f != nullptr) {
			ReadFileVisitor reader;
			f->accept(&reader);
			fs->closeFile(f);
		}
	}
	else if (vs.size() == 2 && vs[1] == "-d") {
		string st = CWD + '/' + vs[0];
		AbstractFile* f = fs->openFile(st);
		if (f != nullptr) {
			vector<char> c = f->read();
			for (size_t i = 0; i < c.size(); ++i) {
				cout << c[i];
			}
			cout << endl;
		}
		fs->closeFile(f);
	}
	
	return success;
}

void DisplayCommand::displayInfo() {
	cout << "displays the contents of the current file" << endl;
	cout << "Usage: ds" << endl;
}