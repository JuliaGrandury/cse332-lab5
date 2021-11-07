#pragma once
#include "AbstractCommand.h"

class DisplayCommand : public AbstractCommand {
public:
	DisplayCommand(AbstractFileSystem* fileSys);
	virtual int execute(std::string& CWD, std::string options) override;
	virtual void displayInfo() override;
	virtual ~DisplayCommand() = default;
private:
	AbstractFileSystem* fs;
};