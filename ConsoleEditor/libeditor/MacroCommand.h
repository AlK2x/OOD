#pragma once
#include "AbstractCommand.h"
class CMacroCommand :
	public CAbstractCommand
{
public:
	void AddCommand(std::unique_ptr<ICommand> command);

protected:

	virtual void DoExecute() override;
	virtual void DoUnexecute() override;

private:
	std::vector<std::unique_ptr<ICommand>> m_commands;
};

