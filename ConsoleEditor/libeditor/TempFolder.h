#pragma once

class CTempFolder
{
public:
	CTempFolder();

	boost::filesystem::path GetPath() const;
	boost::filesystem::path GetImagePath() const;

	~CTempFolder();
private:
	boost::filesystem::path m_path;
	boost::filesystem::path m_relativeImagePath;
};

