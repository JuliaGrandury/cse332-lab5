/*
Author: Jon Shidal
Purpose: CSE 332 lab 5
*/

#include "RemoveCommand.h"
#include<iostream>
#include "DirectoryFile.h"

using namespace std;

RemoveCommand::RemoveCommand(AbstractFileSystem* fileSys) : fs(fileSys) {}

// removes a file from the current working directory
int RemoveCommand::execute(std::string& CWD, std::string options) {
	vector<string> vs;
	string::size_type pos = 0;
	string::size_type prev = 0;
	while ((pos = options.find(' ', prev)) != std::string::npos) {
		vs.push_back(options.substr(prev, pos - prev));
		prev = pos + 1;
	}
	vs.push_back(options.substr(prev));
	string fpa = CWD + '/' + vs[0];
	int result = fs->deleteFile(fpa);
	if (vs.size() == 1) {
		//string fullPath = CWD;
		//fullPath += '/';
		//fullPath += options;
		cout << fpa << endl;
		
		if (result == AbstractFileSystem::filedoesnotexist) {
			cout << "File does not exist" << endl;
			return filedoesnotexist;
		}
		else if (result == AbstractFileSystem::fileisopen) {
			cout << "File is currently in use" << endl;
			return fileinuse;
		}
		else if (result == AbstractFileSystem::directorynotempty) {
			cout << "This directory is not empty" << endl;
			return directorynotempty;
		}
	}
		if (vs.size() == 2 && vs[1] == "-r") {
			/*
			if (result == AbstractFileSystem::filedoesnotexist) {
				cout << "File does not exist" << endl;
				return filedoesnotexist;
			}
			else if (result == AbstractFileSystem::fileisopen) {
				cout << "File is currently in use" << endl;
				return fileinuse;
			}
			else if (result == AbstractFileSystem::directorynotempty) {
				cout << "This directory is not empty" << endl; */
			AbstractFile* fc = fs->openFile(fpa);
			vector<char> ch = fc->read();
			string st(ch.begin(), ch.end());
			vector<string> ves;
			string::size_type posi = 0;
			string::size_type previ = 0;
			while ((posi = st.find('\n', previ)) != std::string::npos) {
				ves.push_back(st.substr(previ, posi - previ));
				previ = posi + 1;
			}
			ves.push_back(st.substr(previ));
			for (size_t i = 0; i < ves.size(); ++i) {
				//cout << vs[i];
				string str = fpa + '/' + ves[i];
				int res = fs->deleteFile(str);
				//AbstractFile* fo = fs->openFile(str);
				//if (fo != nullptr) {
					//fs->closeFile(fo);
					
				//}
			}
			//fs->closeFile()
		
			fs->closeFile(fc);
			if (fc->getSize() == 0) {
				fs->deleteFile(fpa);
			}
			else {
				cout << "Could not completely empty directory" << endl;
			}
			//fs->deleteFile(fpa);
		}

	//AbstractFile* f = fs->openFile(fullPath);
	//dynamic_cast<AbstractFile*> f;
	//if (f->getSize() != 0) {

	//}
	//for (size_t i = 0; )
	//DirectoryFile* 
	return success;
}
void RemoveCommand::displayInfo() {
	cout << "touch removes a file from the file system and then deletes the file" << endl;
	cout << "Usage: rm <filename>" << endl;
}