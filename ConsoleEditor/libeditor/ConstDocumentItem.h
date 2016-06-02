#pragma once
#include <memory>
#include <string>
#include "IParagraph.h"
#include "IImage.h"

class CConstDocumentItem
{
public:
	CConstDocumentItem() {}
	CConstDocumentItem(std::shared_ptr<IImage> image) : m_image(image) {}
	CConstDocumentItem(std::shared_ptr<IParagraph> paragraph) : m_paragraph(paragraph) {}
	// Возвращает указатель на константное изображение, либо nullptr,
	// если элемент не является изображением
	std::shared_ptr<const IImage> GetImage()const;
	// Возвращает указатель на константный параграф, либо nullptr, если элемент не является параграфом
	std::shared_ptr<const IParagraph> GetParagraph()const;
	virtual ~CConstDocumentItem() = default;
protected:
	std::shared_ptr<const IImage> m_image;
	std::shared_ptr<const IParagraph> m_paragraph;
};
