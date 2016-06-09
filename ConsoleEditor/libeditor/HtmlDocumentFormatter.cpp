#include "stdafx.h"
#include "HtmlDocumentFormatter.h"

CHtmlDocumentFormatter::CHtmlDocumentFormatter()
{
	m_htmlEntities.push_back({ '&', "&amp;" });
	m_htmlEntities.push_back({ '<', "&lt;" });
	m_htmlEntities.push_back({ '>', "&gt;" });
	m_htmlEntities.push_back({ '"', "&quot;" });
}

void CHtmlDocumentFormatter::FormatDocument(IDocument const & document, std::ostream & out)
{
	out << boost::format{ R"(
<!DOCTYPE html>
<html>
	<head>
		<title>%1%</title>
	</head>
	<body>)" } % document.GetTitle();

	for (size_t i = 0; i < document.GetItemsCount(); ++i)
	{
		out << FormatDocumentItem(document.GetItem(i), i) << std::endl;
	}

	out << R"(
	</body>
</html>)";
}

std::string CHtmlDocumentFormatter::EscapeHtmlEntities(std::string & str)
{
	std::string escaped = str;
	for (auto const & htmlEntity : m_htmlEntities)
	{
		std::string::size_type pos = escaped.find_first_of(htmlEntity.first);
		while (pos != std::string::npos)
		{
			escaped.replace(pos, 1, htmlEntity.second);
			pos = escaped.find_first_of(htmlEntity.first, pos + htmlEntity.second.size());
		}
	}
	return escaped;
}

std::string CHtmlDocumentFormatter::FormatDocumentItem(CConstDocumentItem const & item, size_t position)
{
	(void)position;
	return GetFormattedString(
		item,
		"<p>%1%</p>",
		R"(<img height="%1%" width="%2%" src="%3%" />)",
		boost::none,
		std::bind(&CHtmlDocumentFormatter::EscapeHtmlEntities, this, std::placeholders::_1)
	);
}
