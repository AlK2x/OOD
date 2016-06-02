#pragma once
#include <map>
#include <functional>
#include "ConstDocumentItem.h"

class CDocumentItemFormatter
{
public:
	CDocumentItemFormatter();
	std::string FormatForHtml(CConstDocumentItem const & item);
	std::string FormatForList(CConstDocumentItem const & item, size_t position);

	~CDocumentItemFormatter() = default;

private:
	std::string EscapeHtmlEntities(std::string & str);
	std::string NoEscape(std::string & str);

	std::string GetFormattedString(
		CConstDocumentItem const & item,
		std::string paragraphPattern,
		std::string imagePattern,
		boost::optional<size_t> position,
		std::function<std::string(std::string&)> escapeFn
	);

	std::map<char, std::string> m_htmlEntities;
};

