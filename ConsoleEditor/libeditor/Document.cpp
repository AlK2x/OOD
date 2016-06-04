#include "stdafx.h"
#include "Document.h"
#include "ChangeStringCommand.h"
#include "InsertDocumentItemCommand.h"
#include "DeleteDocumentItemCommand.h"

using namespace std;
namespace fs = boost::filesystem;

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
		throw std::out_of_range("Element does not exist.");
	}

	return *item.get();
}

size_t CDocument::GetItemsCount() const
{
	return m_items.GetSize();
}

void CDocument::Save(const std::string & path) const
{
	try
	{
		fs::path p{ path };
		fs::path parentPath(p.parent_path());
		fs::file_status s = fs::status(p);
		if (!fs::exists(s) && !fs::is_directory(parentPath))
		{
			fs::create_directory(parentPath);
		}

		fs::ofstream ofs(path, fs::ofstream::out);
		ofs << "Hello boost NEW filisystem" + path;
	}
	catch (const std::exception & ex)
	{
		throw ex;
	}
}

void CDocument::DeleteItem(size_t index)
{
	CDocumentItemPtr item = m_items.GetItem(index);
	if (item == nullptr)	
	{
		throw std::out_of_range("Element does not exist.");
	}

	m_history.AddAndExecuteCommand(std::make_unique<CDeleteDocumentItemCommand>(m_items, item, index));
}

//CDocumentItem CDocument::GetItem(size_t index)
//{
//	CDocumentItemPtr item = m_items.GetItem(index);
//	if (item == nullptr)
//	{
//		throw std::out_of_range("Element does not exist. Index: " + index);
//	}
//
//	return *item.get();
//}

std::shared_ptr<IParagraph> CDocument::InsertParagraph(const std::string & text, boost::optional<size_t> position)
{
	IParagraphPtr paragraph = std::make_shared<CParagraph>();
	paragraph->SetText(text);
	CDocumentItemPtr item = std::make_shared<CDocumentItem>(paragraph);

	m_history.AddAndExecuteCommand(std::make_unique<CInsertDocumentItemCommand>(m_items, item, position));
	return paragraph;
}
