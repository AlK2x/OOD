#include "stdafx.h"
#include <locale>
#include "Document.h"
#include "ImageItem.h"
#include "ChangeStringCommand.h"
#include "InsertDocumentItemCommand.h"
#include "DeleteDocumentItemCommand.h"
#include "MacroCommand.h"
#include "ResizeImageCommand.h"

using namespace std;
namespace fs = boost::filesystem;

CDocument::CDocument()
	:m_tempDirectory(std::make_unique<CTempFolder>())
{
}

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

CDocumentItem CDocument::GetItem(size_t index)
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
	fs::ofstream ofs(path, fs::ofstream::out);
	CHtmlDocumentFormatter formatter(*(m_tempDirectory.get()));
	formatter.FormatDocument(*this, ofs);
}

std::shared_ptr<const IImage> CDocument::InsertImage(const std::string & path, int width, int height, boost::optional<size_t> position)
{
	fs::path sourcePath(path);
	if (!fs::exists(sourcePath) || fs::is_directory(sourcePath))
	{
		throw std::runtime_error("Source file does not exist");
	}

	fs::path relativeImagePath = m_tempDirectory->GetImagePath();
	relativeImagePath /= fs::unique_path();
	relativeImagePath += sourcePath.extension();

	fs::path tempFilePath = m_tempDirectory->GetPath();
	tempFilePath /= relativeImagePath;

	fs::copy_file(sourcePath, tempFilePath, fs::copy_option::overwrite_if_exists);

	IImagePtr m_image = std::make_shared<CImageItem>(m_history, tempFilePath, relativeImagePath, width, height);
	CDocumentItemPtr item = std::make_shared<CDocumentItem>(m_image);
	
	m_history.AddAndExecuteCommand(std::make_unique<CInsertDocumentItemCommand>(m_items, item, position));

	return m_image;
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

std::shared_ptr<const IParagraph> CDocument::InsertParagraph(const std::string & text, boost::optional<size_t> position)
{
	IParagraphPtr paragraph = std::make_shared<CParagraph>(m_history, text);
	CDocumentItemPtr item = std::make_shared<CDocumentItem>(paragraph);

	m_history.AddAndExecuteCommand(std::make_unique<CInsertDocumentItemCommand>(m_items, item, position));
	return paragraph;
}

