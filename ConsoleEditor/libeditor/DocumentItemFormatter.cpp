#include "stdafx.h"
#include "DocumentItemFormatter.h"

using boost::format;

CDocumentItemFormatter::CDocumentItemFormatter()
{
	m_htmlEntities['<'] = "&lt;";
	m_htmlEntities['>'] = "&gt;";
	m_htmlEntities['"'] = "&quot;";
}

std::string CDocumentItemFormatter::FormatForHtml(CConstDocumentItem const & item)
{
	return GetFormattedString(
		item,
		"<p>%1%</p>",
		"<img height=\"%1%\" width=\"%2%\" src=\"%3%\" />",
		boost::none,
		std::bind(&CDocumentItemFormatter::EscapeHtmlEntities, this, std::placeholders::_1)
	);
}

std::string CDocumentItemFormatter::FormatForList(CConstDocumentItem const & item, size_t position)
{
	return GetFormattedString(
		item,
		"%2%. Paragraph: %1%",
		"%4%. Image: %1% %2% %3%",
		position,
		std::bind(&CDocumentItemFormatter::NoEscape, this, std::placeholders::_1)
	);
}

std::string CDocumentItemFormatter::EscapeHtmlEntities(std::string & str)
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

std::string CDocumentItemFormatter::NoEscape(std::string & str)
{
	return str;
}

std::string CDocumentItemFormatter::GetFormattedString(
	CConstDocumentItem const & item,
	std::string paragraphPattern,
	std::string imagePattern,
	boost::optional<size_t> position,
	std::function<std::string(std::string&)> escapeFn)
{
	std::shared_ptr<const IImage> imagePtr = item.GetImage();
	std::shared_ptr<const IParagraph> paragraphPtr = item.GetParagraph();

	if (paragraphPtr != nullptr)
	{
		std::string paragraphText = paragraphPtr->GetText();
		format fmt(paragraphPattern);
		fmt % escapeFn(paragraphText);
		if (position)
		{
			fmt % position.get();
		}
		return fmt.str();
	}

	if (imagePtr != nullptr)
	{
		format fmt(imagePattern);
		fmt % imagePtr->GetHeight();
		fmt % imagePtr->GetWidth();
		fmt % imagePtr->GetPath();
		if (position)
		{
			fmt % position.get();
		}
		
		return fmt.str();
	}

	return "";
}
