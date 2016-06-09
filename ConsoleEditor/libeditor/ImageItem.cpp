#include "stdafx.h"
#include "ImageItem.h"

namespace fs = boost::filesystem;

CImageItem::CImageItem(	boost::filesystem::path tempFilePath, boost::filesystem::path relativePathToImage, int width, int height)
	:m_width(width), m_height(height), m_imageRelativePath(relativePathToImage), m_pathToTempImage(tempFilePath)
{
}

CImageItem::~CImageItem()
{
	fs::remove(m_pathToTempImage);
}

boost::filesystem::path CImageItem::GetPath() const
{
	return m_imageRelativePath;
}

boost::filesystem::path CImageItem::GetTempPath() const
{
	return m_imageRelativePath;
}

int CImageItem::GetWidth() const
{
	return m_width;
}

int CImageItem::GetHeight() const
{
	return m_height;
}

void CImageItem::Resize(int width, int height)
{
	m_width = width;
	m_height = height;
}
