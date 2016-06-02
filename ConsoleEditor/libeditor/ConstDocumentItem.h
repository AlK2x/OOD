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
	// ���������� ��������� �� ����������� �����������, ���� nullptr,
	// ���� ������� �� �������� ������������
	std::shared_ptr<const IImage> GetImage()const;
	// ���������� ��������� �� ����������� ��������, ���� nullptr, ���� ������� �� �������� ����������
	std::shared_ptr<const IParagraph> GetParagraph()const;
	virtual ~CConstDocumentItem() = default;
protected:
	std::shared_ptr<const IImage> m_image;
	std::shared_ptr<const IParagraph> m_paragraph;
};
