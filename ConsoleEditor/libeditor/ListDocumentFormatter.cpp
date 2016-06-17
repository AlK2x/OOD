#include "stdafx.h"
#include "ListDocumentFormatter.h"

namespace fs = boost::filesystem;

void CListDocumentFormatter::FormatHeader(IDocument const & document, std::ostream & out)
{
	out << "-------------" << std::endl;
	out << "Title: " << document.GetTitle() << std::endl;
}

void CListDocumentFormatter::FormatDocumentItem(CConstDocumentItem const & item, size_t position, std::ostream & out)
{
	std::shared_ptr<const IImage> imagePtr = item.GetImage();
	std::shared_ptr<const IParagraph> paragraphPtr = item.GetParagraph();

	if (paragraphPtr != nullptr)
	{
		out << boost::format(R"(%1%. Paragraph: %2%)") % position % paragraphPtr->GetText() << std::endl;
	}

	if (imagePtr != nullptr)
	{
		out << boost::format(R"(%1%. Image: %2% %3% %4%)") 
			% position 
			% imagePtr->GetWidth() 
			% imagePtr->GetHeight()
			% imagePtr->GetPath().string()
			<< std::endl;
	}
}

void CListDocumentFormatter::FormatFooter(std::ostream & out)
{
	out << "-------------" << std::endl;
}

void CListDocumentFormatter::CreateDocumentFilesImpl(IDocument const & document, std::string const & path)
{
	(void)document;
	(void)path;
}
