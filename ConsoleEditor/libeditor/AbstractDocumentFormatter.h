#pragma once
#include "IDocument.h"
#include "ConstDocumentItem.h"

class CAbstractDocumentFormatter
{
public:

	virtual void FormatDocument(IDocument const & document, std::ostream & out) = 0;

	virtual ~CAbstractDocumentFormatter() = default;

protected:
	virtual std::string FormatDocumentItem(CConstDocumentItem const & item, size_t position) = 0;

	std::string GetFormattedString(
		CConstDocumentItem const & item,
		std::string paragraphPattern,
		std::string imagePattern,
		boost::optional<size_t> position,
		std::function<std::string(std::string&)> escapeFn
	);
};