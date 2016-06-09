#include "stdafx.h"
#include "Paragraph.h"
#include <iostream>

std::string CParagraph::GetText() const
{
	return m_text;
}

void CParagraph::SetText(const std::string & text)
{
	m_text = text;
}

