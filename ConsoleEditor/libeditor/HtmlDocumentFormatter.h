#pragma once
#include "AbstractDocumentFormatter.h"
#include "TempFolder.h"

class CHtmlDocumentFormatter : public CAbstractDocumentFormatter
{
public:
	CHtmlDocumentFormatter(CTempFolder const & tempFolder);

protected:
	void FormatHeader(IDocument const & document, std::ostream & out) override;
	void FormatDocumentItem(CConstDocumentItem const & item, size_t position, std::ostream & out) override;
	void FormatFooter(std::ostream & out) override;
	void CreateDocumentFilesImpl(IDocument const & document, std::string const & path) override;

private:
	std::string EscapeHtmlEntities(const std::string & str);

	std::vector < std::pair<char, std::string>> m_htmlEntities;
	const CTempFolder & m_tempFolder;
};

