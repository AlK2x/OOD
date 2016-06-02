#pragma once
#include "AbstractCommand.h"
class CChangeParagraphCommand : public CAbstractCommand
{
public:
	CChangeParagraphCommand();

protected:
	virtual void DoExecute() override;
	virtual void DoUnexecute() override;

private:

};

