#pragma once
#include "IDocument.h"
#include "ConstDocumentItem.h"

class CAbstractDocumentFormatter
{
public:
	void FormatDocument(IDocument const & document, std::ostream & out);
	void CreateDocumentFiles(IDocument const & document, std::string const & path);

	virtual ~CAbstractDocumentFormatter() = default;

protected:

	virtual void FormatHeader(IDocument const & document, std::ostream & out) = 0;
	virtual void FormatDocumentItem(CConstDocumentItem const & item, size_t position, std::ostream & out) = 0;
	virtual void FormatFooter(std::ostream & out) = 0;
	virtual void CreateDocumentFilesImpl(IDocument const & document, std::string const & path) = 0;

};