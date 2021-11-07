/*
Author: Jon Shidal
Purpose: CSE 332 lab 5
*/
//ls
#include "LSCommand.h"
#include "ReadFileVisitor.h"
#include "ReadMetadataFileVisitor.h"
#include<iostream>

using namespace std;

LSCommand::LSCommand(AbstractFileSystem * fileSys) : fs(fileSys) {}

int LSCommand::execute(std::string& CWD, std::string options) {
	vector<string> vs;
	string::size_type pos = 0;
	string::size_type prev = 0;
	while ((pos = options.find(' ', prev)) != std::string::npos) {
		vs.push_back(options.substr(prev, pos - prev));
		prev = pos + 1;
	}
	vs.push_back(options.substr(prev));
	if (options.size() == 0) {
		AbstractFile* f = fs->openFile(CWD);
		if (f != nullptr) { // file creation failed
			//cout << "failed to open directory" << endl;
			//return directorydoesnotexist;
		//}
		//else {
			ReadFileVisitor reader;
			f->accept(&reader);
			fs->closeFile(f);
		}
	}
	else if (vs.size() == 1 && vs[0] == "-l") {
		AbstractFile* f = fs->openFile(CWD);
		fs->closeFile(f);
		if (f != nullptr) { // file creation failed
			//cout << "failed to open directory" << endl;
			//return directorydoesnotexist;
		//}
		//else {
			vector<char> c = f->read();
			string s(c.begin(), c.end());
			vector<string> ves;
			string::size_type posi = 0;
			string::size_type previ = 0;
			while ((posi = s.find('\n', previ)) != std::string::npos) {
				ves.push_back(s.substr(previ, posi - previ));
				previ = posi + 1;
			}
			ves.push_back(s.substr(previ));
			for (size_t i = 0; i < ves.size(); ++i) {
				string str = CWD + '/' + ves[i]; 
				f = fs->openFile(str);
				fs->closeFile(f);
				if (f != nullptr) {
					ReadMetadataFileVisitor r;
					f->accept(&r);
					fs->closeFile(f);
				}
			}
		}
		fs->closeFile(f);
	}
	//s = CWD + "/" + s;
/*
	//cout << c[6];
	//string str(c.begin(), c.end());
	//string sub = str.substr(0, 5);
	//cout << sub << endl;;
	if (options == "-l") {
		
		//AbstractFile* af = fs->openFile(s);
		for (size_t i = 0; i < vs.size(); ++i) {
			//cout << vs[i];
			string str = CWD + '/' + vs[i];
			f = fs->openFile(str);
			if (f != nullptr) {
				ReadMetadataFileVisitor r;
				f->accept(&r);
				fs->closeFile(f);
			}
		}

		//fs->closeFile(af);
	} */
	//fs->closeFile(f);

	return success;
}
void LSCommand::displayInfo() {
	cout << "lists the contents of the current directory" << endl;
	cout << "Usage: ls" << endl;
}