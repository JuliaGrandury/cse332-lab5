#include "CatCommand.h"
#include <iostream>

using namespace std;

CatCommand::CatCommand(AbstractFileSystem* fileSys) : fs(fileSys) {}

int CatCommand::execute(std::string& CWD, std::string options) {
	vector<string> vs;
	string::size_type pos = 0;
	string::size_type prev = 0;
	while ((pos = options.find(' ', prev)) != std::string::npos) {
		vs.push_back(options.substr(prev, pos - prev));
		prev = pos + 1;
	}
	vs.push_back(options.substr(prev));
	string st = CWD + '/' + vs[0];
	AbstractFile* f = fs->openFile(st);
	if (vs.size() == 1) {
		vector<char> v;
		string input;
		cout << "Enter data you'd like to write to the file. Enter :wq to save and quit or enter :q to quit";
		cout << " without saving" << endl;
		cout << st << endl;
		while (1) {
			input = prompt();
			//f->append(v);
			if (input == ":q") {
				fs->closeFile(f);
				return success;
				//return userquit;
			}
			else if (input == ":wq") {
				//vector<char> v(input.begin(), input.end());
				f->write(v);
				fs->closeFile(f);
				return success;
			}
			else {
				std::copy(input.begin(), input.end(), back_inserter(v));
				v.push_back('\n');

				//v.push_back(input.begin(), input.end());
			}
		}
	}
	else if (vs.size() == 2 && vs[1] == "-a") {

		//AbstractFile* copy = fs->openFile(st);
		if (f != nullptr) {
			vector<char> c = f->read();
			for (size_t i = 0; i < c.size(); ++i) {
				cout << c[i];
			}
			cout << endl;
			//string input = prompt();
			vector<char> v;
			string input;
			cout << "Enter data you'd like to write to the file. Enter :wq to save and quit or enter :q to quit";
			cout << " without saving" << endl;
			cout << st << endl;
			while (1) {
				input = prompt();
				//f->append(v);
				if (input == ":q") {
					fs->closeFile(f);
					return success;
					//return userquit;
				}
				else if (input == ":wq") {
					//vector<char> v(input.begin(), input.end());
					f->append(v);
					fs->closeFile(f);
					return success;
				}
				else {
					std::copy(input.begin(), input.end(), back_inserter(v));
					v.push_back('\n');

					//v.push_back(input.begin(), input.end());
				}
			}

		}

	}
}
void CatCommand::displayInfo() {
	cout << "concatenates and writes files" << endl;
	cout << "Usage: ds" << endl;
}

string CatCommand::prompt() {

	string input;
	getline(cin, input);
	return input;
}