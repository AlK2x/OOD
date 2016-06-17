#pragma once
#include "AbstractDocumentFormatter.h"

class CHtmlDocumentFormatter : public CAbstractDocumentFormatter
{
public:
	CHtmlDocumentFormatter();
	void FormatDocument(IDocument const & document, std::ostream & out) override;

protected:

	std::string FormatDocumentItem(CConstDocumentItem const & item, size_t position) override;

private:
	std::string EscapeHtmlEntities(const std::string & str);

	std::vector < std::pair<char, std::string>> m_htmlEntities;
};

