#pragma once
#include "ConstDocumentItem.h"

class CDocumentItem;
typedef std::shared_ptr<CDocumentItem> CDocumentItemPtr;

class CDocumentItem : public CConstDocumentItem
{
public:
	CDocumentItem(std::shared_ptr<IImage> image) : CConstDocumentItem(image) {}
	CDocumentItem(std::shared_ptr<IParagraph> paragraph) : CConstDocumentItem(paragraph) {}
	// ���������� ��������� �� �����������, ���� nullptr, ���� ������� �� �������� ������������
	std::shared_ptr<IImage> GetImage();
	// ���������� ��������� �� ��������, ���� nullptr, ���� ������� �� �������� ����������
	std::shared_ptr<IParagraph> GetParagraph();
};
