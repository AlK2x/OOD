#pragma once
#include "IDocument.h"
#include "History.h"
#include "Paragraph.h"
#include "DocumentItem.h"
#include "DocumentItemCollection.h"

typedef std::shared_ptr<IParagraph> IParagraphPtr;

class CDocument : public IDocument
{
public:
	void SetTitle(const std::string & title) override;
	std::string GetTitle() const override;
	virtual std::shared_ptr<IParagraph> InsertParagraph(const std::string & text, boost::optional<size_t> position = boost::none) override;

	bool CanUndo() const override;
	void Undo() override;
	bool CanRedo() const override;
	void Redo() override;

	CConstDocumentItem GetItem(size_t index) const override;
	size_t GetItemsCount() const override;

private:
	std::string m_title;
	CHistory m_history;
	CDocumentItemCollection m_items;

	
};