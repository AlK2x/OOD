#pragma once
#include "AbstractCommand.h"
#include "IImage.h"

class CResizeImageCommand : public CAbstractCommand
{
public:
	CResizeImageCommand(int & width, int & height, int newWidth, int newHight);
	~CResizeImageCommand() = default;

protected:
	virtual void DoExecute() override;
	virtual void DoUnexecute() override;

private:
	int & m_width;
	int & m_height;

	int m_newWidth;
	int m_newHeight;
};

