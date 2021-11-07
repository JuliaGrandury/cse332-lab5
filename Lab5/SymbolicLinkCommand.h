#pragma once
#include "AbstractFile.h"
#include "AbstractCommand.h"

class SymbolicLinkCommand : public AbstractCommand {
public:
	SymbolicLinkCommand(AbstractFileSystem* fileSys);
	virtual int execute(std::string& CWD, std::string options) override;
	virtual void displayInfo() override;
	virtual ~SymbolicLinkCommand() = default;
private:
	AbstractFileSystem* fs;
};
