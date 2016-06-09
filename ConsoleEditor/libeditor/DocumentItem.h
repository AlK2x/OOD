#pragma once
#include "ConstDocumentItem.h"

class CDocumentItem;
typedef std::shared_ptr<CDocumentItem> CDocumentItemPtr;

class CDocumentItem : public CConstDocumentItem
{
public:
	CDocumentItem(std::shared_ptr<IImage> m_image) : CConstDocumentItem(m_image) {}
	CDocumentItem(std::shared_ptr<IParagraph> paragraph) : CConstDocumentItem(paragraph) {}
	// Возвращает указатель на изображение, либо nullptr, если элемент не является изображением
	std::shared_ptr<IImage> GetImage();
	// Возвращает указатель на параграф, либо nullptr, если элемент не является параграфом
	std::shared_ptr<IParagraph> GetParagraph();
};
