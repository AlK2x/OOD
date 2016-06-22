#include "stdafx.h"
#include "HtmlDocumentFormatter.h"

namespace fs = boost::filesystem;

CHtmlDocumentFormatter::CHtmlDocumentFormatter(CTempFolder const & tempFolder)
	:m_tempFolder(tempFolder)
{
	m_htmlEntities.push_back({ '&', "&amp;" });
	m_htmlEntities.push_back({ '<', "&lt;" });
	m_htmlEntities.push_back({ '>', "&gt;" });
	m_htmlEntities.push_back({ '"', "&quot;" });
}

std::string CHtmlDocumentFormatter::EscapeHtmlEntities(const std::string & str)
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

void CHtmlDocumentFormatter::CreateDocumentFilesImpl(IDocument const & document, std::string const & path)
{
	fs::path p{ path };
	fs::path parentPath(p.parent_path());

	fs::file_status s = fs::status(p);
	if (!fs::exists(s) && !fs::is_directory(p))
	{
		fs::create_directory(parentPath);
	}

	fs::path imagePath(parentPath);
	imagePath /= m_tempFolder.GetImagePath();
	if (!fs::is_directory(imagePath))
	{
		fs::create_directory(imagePath);
	}
	else
	{
		fs::remove_all(imagePath);
		fs::create_directory(imagePath);
	}

	for (size_t i = 0; i < document.GetItemsCount(); ++i)
	{
		CConstDocumentItem item = document.GetItem(i);
		std::shared_ptr<const IImage> m_image = item.GetImage();
		if (m_image != nullptr)
		{
			fs::path from = m_tempFolder.GetPath();
			from /= m_image->GetPath();

			fs::path absoluteImagePath(parentPath);

			absoluteImagePath /= m_image->GetPath();
			fs::copy_file(from, absoluteImagePath, fs::copy_option::overwrite_if_exists);
		}
	}
}

void CHtmlDocumentFormatter::FormatHeader(IDocument const & document, std::ostream & out)
{
	std::string escapedTitle = EscapeHtmlEntities(document.GetTitle());
	out << boost::format{ R"(
<!DOCTYPE html>
<html>
	<head>
		<title>%1%</title>
	</head>
	<body>)" } % escapedTitle;
}

void CHtmlDocumentFormatter::FormatDocumentItem(CConstDocumentItem const & item, size_t position, std::ostream & out)
{
	(void)position;
	std::shared_ptr<const IImage> imagePtr = item.GetImage();
	std::shared_ptr<const IParagraph> paragraphPtr = item.GetParagraph();

	if (paragraphPtr != nullptr)
	{
		out << boost::format(R"(<p>%1%</p>)") % paragraphPtr->GetText() << std::endl;
	}

	if (imagePtr != nullptr)
	{
		out << boost::format(R"(<img height="%1%" width="%2%" src="%3%" />)")
			% imagePtr->GetWidth()
			% imagePtr->GetHeight()
			% imagePtr->GetPath().string()
			<< std::endl;
	}
}

void CHtmlDocumentFormatter::FormatFooter(std::ostream & out)
{
	out << R"(
	</body>
</html>)";
}

