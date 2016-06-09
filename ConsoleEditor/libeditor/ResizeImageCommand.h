#pragma once
#include "AbstractCommand.h"
#include "IImage.h"

class CResizeImageCommand :
	public CAbstractCommand
{
public:
	CResizeImageCommand(IImagePtr image, int width, int height);
	~CResizeImageCommand() = default;

	virtual void DoExecute() override;
	virtual void DoUnexecute() override;
private:
	int m_width;
	int m_height;
	IImagePtr m_image;
};

