#pragma once
#include "AbstractDocumentFormatter.h"

class CListDocumentFormatter : public CAbstractDocumentFormatter
{
protected:

	void FormatHeader(IDocument const & document, std::ostream & out) override;
	void FormatDocumentItem(CConstDocumentItem const & item, size_t position, std::ostream & out) override;
	void FormatFooter(std::ostream & out) override;
	virtual void CreateDocumentFilesImpl(IDocument const & document, std::string const & path) override;
};
