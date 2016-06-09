#include "stdafx.h"
#include "ListDocumentFormatter.h"

void CListDocumentFormatter::FormatDocument(IDocument const & document, std::ostream & out)
{
	out << "Title: " << document.GetTitle() << std::endl;
	for (size_t i = 0; i < document.GetItemsCount(); ++i)
	{
		out << FormatDocumentItem(document.GetItem(i), i) << std::endl;
	}
}

std::string CListDocumentFormatter::FormatDocumentItem(CConstDocumentItem const & item, size_t position)
{
	return GetFormattedString(
		item,
		"%2%. Paragraph: %1%",
		"%4%. Image: %1% %2% %3%",
		position,
		std::bind(&CListDocumentFormatter::NoEscape, this, std::placeholders::_1)
	);
}

std::string CListDocumentFormatter::NoEscape(std::string & str)
{
	return str;
}
