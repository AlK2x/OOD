#pragma once
#include "IImage.h"
#include "TempFolder.h"
#include "TempFolder.h"

class CImageItem : public IImage
{
public:
	CImageItem(boost::filesystem::path tempFilePath, boost::filesystem::path relativePathToImage, int width, int height);

	~CImageItem();

	boost::filesystem::path GetPath() const override;
	boost::filesystem::path GetTempPath() const;
	int GetWidth() const override;
	int GetHeight() const override;

	void Resize(int width, int height) override;
private:
	int m_width;
	int m_height;

	boost::filesystem::path m_imageRelativePath;
	boost::filesystem::path m_pathToTempImage;
};

