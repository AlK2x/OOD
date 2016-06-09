#include "stdafx.h"
#include "TempFolder.h"

namespace fs = boost::filesystem;

CTempFolder::CTempFolder()
	:m_path(fs::temp_directory_path()), m_relativeImagePath("images")
{
	m_path /= fs::unique_path("ConsoleEditor_Temp_%%%%");
	fs::create_directory(m_path);
	fs::path m_imagePath(m_path);
	m_imagePath /= m_relativeImagePath;
	std::cout << m_imagePath << std::endl;
	fs::create_directory(m_imagePath);
}

fs::path CTempFolder::GetPath() const
{
	return m_path;
}

boost::filesystem::path CTempFolder::GetImagePath() const
{
	return m_relativeImagePath;
}


CTempFolder::~CTempFolder()
{
	fs::remove_all(m_path);
}
