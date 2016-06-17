#include "stdafx.h"
#include "ResizeImageCommand.h"

CResizeImageCommand::CResizeImageCommand(int & width, int & height, int newWidth, int newHight)
	:m_width(width), m_height(height), m_newHeight(newHight), m_newWidth(newWidth)
{
}

void CResizeImageCommand::DoExecute()
{
	std::swap(m_newHeight, m_height);
	std::swap(m_newWidth, m_width);
}

void CResizeImageCommand::DoUnexecute()
{
	std::swap(m_newHeight, m_height);
	std::swap(m_newWidth, m_width);
}
