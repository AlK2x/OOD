#pragma once
#include "AbstractDocumentFormatter.h"

class CListDocumentFormatter : public CAbstractDocumentFormatter
{
public:

	virtual void FormatDocument(IDocument const & document, std::ostream & out) override;

protected:

	virtual std::string FormatDocumentItem(CConstDocumentItem const & item, size_t position) override;

private:

	std::string NoEscape(std::string & str);
};

