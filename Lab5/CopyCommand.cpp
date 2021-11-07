#include "CopyCommand.h"
#include <iostream>

using namespace std;

CopyCommand::CopyCommand(AbstractFileSystem* fileSys) : fs(fileSys) {}

int CopyCommand::execute(std::string& CWD, std::string options) {
	vector<string> vs;
	string::size_type pos = 0;
	string::size_type prev = 0;
	while ((pos = options.find(' ', prev)) != std::string::npos) {
		vs.push_back(options.substr(prev, pos - prev));
		prev = pos + 1;
	}
	vs.push_back(options.substr(prev));
	if (vs.size() == 0 || vs.size() == 1) {
		cout << "Please put in file and directory you want to copy to" << endl;
		return filedoesnotexist;
	}
	string st = CWD + '/' + vs[0];
	AbstractFile* toCopy = fs->openFile(st);
	fs->closeFile(toCopy);
	if (toCopy == nullptr) {
		cout << "File doesn't exist" << endl;
		return filedoesnotexist;
	}
	//cout << vs[1];
	AbstractFile* copy = toCopy->clone();
	if (copy == nullptr) {
		cout << "Cannot copy a directory" << endl;
		delete copy;
		return cannotcopydirectory;
	}
	//toCopy = nullptr;
	string path1 = vs[1] + '/' + copy->getName();
	//cout << copy->getName();
	//cout << path << endl;
	int res = fs->addFile(path1, copy);
	if (res != success) {
		delete copy;
		cout << "Invalid request" << endl;
	}

	return success;

	return success;
}

void CopyCommand::displayInfo() {
	cout << "Copies existing files into new locations" << endl;
	cout << "Usage: cp" << endl;
}