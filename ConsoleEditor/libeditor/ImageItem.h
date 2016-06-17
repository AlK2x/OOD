#pragma once
#include "IImage.h"
#include "TempFolder.h"
#include "TempFolder.h"
#include "History.h"

class CImageItem : public IImage
{
public:
	CImageItem(CHistory & m_history, boost::filesystem::path tempFilePath, boost::filesystem::path relativePathToImage, int width, int height);

	~CImageItem();

	boost::filesystem::path GetPath() const override;
	boost::filesystem::path GetTempPath() const;
	int GetWidth() const override;
	int GetHeight() const override;

	void Resize(int width, int height) override;
private:
	int m_width;
	int m_height;
	CHistory & m_history;

	boost::filesystem::path m_imageRelativePath;
	boost::filesystem::path m_pathToTempImage;
};

