#pragma once
#include "AbstractCommand.h"

class CatCommand :public AbstractCommand {
public:
	enum {
		s, userquit
	};
	CatCommand(AbstractFileSystem* filesys);
	virtual int execute(std::string& CWD, std::string options) override;
	virtual void displayInfo() override;
	virtual ~CatCommand() = default;

private:
	AbstractFileSystem* fs;
	std::string prompt();
};