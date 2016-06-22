#include "stdafx.h"
#include "AbstractDocumentFormatter.h"

using boost::format;

void CAbstractDocumentFormatter::FormatDocument(IDocument const & document, std::ostream & out)
{
	FormatHeader(document, out);
	for (size_t i = 0; i < document.GetItemsCount(); ++i)
	{
		FormatDocumentItem(document.GetItem(i), i, out);
	}
	FormatFooter(out);
}

void CAbstractDocumentFormatter::CreateDocumentFiles(IDocument const & document, std::string const & path)
{
	CreateDocumentFilesImpl(document, path);
}

