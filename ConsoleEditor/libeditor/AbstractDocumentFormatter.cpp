#include "stdafx.h"
#include "AbstractDocumentFormatter.h"

using boost::format;

std::string CAbstractDocumentFormatter::GetFormattedString(
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
		fmt % imagePtr->GetPath().string();
		if (position)
		{
			fmt % position.get();
		}

		std::cout << imagePtr->GetPath() << std::endl;

		return fmt.str();
	}

	return "";
}

