#include "stdafx.h"
#include "ResizeImageCommand.h"

CResizeImageCommand::CResizeImageCommand(IImagePtr image, int width, int height)
	:m_image(image), m_width(width), m_height(height)
{
}

void CResizeImageCommand::DoExecute()
{
	int tempHeight = m_image->GetHeight();
	int tempWidth = m_image->GetWidth();
	std::swap(tempHeight, m_height);
	std::swap(tempWidth, m_width);
	m_image->Resize(tempWidth, tempHeight);
}

void CResizeImageCommand::DoUnexecute()
{
	int tempHeight = m_image->GetHeight();
	int tempWidth = m_image->GetWidth();
	std::swap(tempHeight, m_height);
	std::swap(tempWidth, m_width);
	m_image->Resize(tempWidth, tempHeight);
}
