#include "stdafx.h"
#include "Document.h"
#include "ChangeStringCommand.h"
#include "InsertDocumentItemCommand.h"

using namespace std;

void CDocument::SetTitle(const std::string & title)
{
	m_history.AddAndExecuteCommand(make_unique<CChangeStringCommand>(m_title, title));
}

std::string CDocument::GetTitle() const
{
	return m_title;
}

bool CDocument::CanUndo() const
{
	return m_history.CanUndo();
}

void CDocument::Undo()
{
	m_history.Undo();
}

bool CDocument::CanRedo() const
{
	return m_history.CanRedo();
}

void CDocument::Redo()
{
	m_history.Redo();
}

CConstDocumentItem CDocument::GetItem(size_t index) const
{
	CDocumentItemPtr item = m_items.GetItem(index);
	if (item == nullptr)
	{
		throw std::out_of_range("Element does not exist. Index: " + index);
	}

	return *item.get();
}

size_t CDocument::GetItemsCount() const
{
	return m_items.GetSize();
}

std::shared_ptr<IParagraph> CDocument::InsertParagraph(const std::string & text, boost::optional<size_t> position)
{
	IParagraphPtr paragraph = std::make_shared<CParagraph>();
	paragraph->SetText(text);
	CDocumentItemPtr item = std::make_shared<CDocumentItem>(paragraph);

	m_history.AddAndExecuteCommand(std::make_unique<CInsertDocumentItemCommand>(m_items, item, position));
	return paragraph;
}
