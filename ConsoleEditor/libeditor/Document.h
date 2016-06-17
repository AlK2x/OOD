#pragma once
#include "IDocument.h"
#include "History.h"
#include "Paragraph.h"
#include "DocumentItem.h"
#include "DocumentItemCollection.h"
#include "HtmlDocumentFormatter.h"
#include "TempFolder.h"

class CDocument : public IDocument
{
public:
	CDocument();

	void SetTitle(const std::string & title) override;
	std::string GetTitle() const override;
	std::shared_ptr<const IParagraph> InsertParagraph(const std::string & text, boost::optional<size_t> position = boost::none) override;

	std::shared_ptr<const IImage> InsertImage(const std::string & path, int width, int height, boost::optional<size_t> position = boost::none) override;

	bool CanUndo() const override;
	void Undo() override;
	bool CanRedo() const override;
	void Redo() override;

	CConstDocumentItem GetItem(size_t index) const override;
	CDocumentItem GetItem(size_t index) override;

	void DeleteItem(size_t index) override;

	size_t GetItemsCount() const override;
	
	void Save(const std::string & path) const override;
	
private:
	std::string m_title;
	CHistory m_history;
	CDocumentItemCollection m_items;
	std::unique_ptr<CTempFolder> m_tempDirectory;
	
};