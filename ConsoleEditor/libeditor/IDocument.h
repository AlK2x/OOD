#pragma once
#include "stdafx.h"
#include <memory>
#include <string>
#include "ConstDocumentItem.h"
#include "DocumentItem.h"
#include "IParagraph.h"

class IDocument
{
public:
	virtual std::shared_ptr<const IParagraph> InsertParagraph(const std::string& text,
		boost::optional<size_t> position = boost::none) = 0;

	virtual std::shared_ptr<const IImage> InsertImage(const std::string& path, int width, int height,
		boost::optional<size_t> position = boost::none) = 0;

	virtual size_t GetItemsCount()const = 0;

	virtual CConstDocumentItem GetItem(size_t index)const = 0;
	virtual CDocumentItem GetItem(size_t index) = 0;

	virtual void DeleteItem(size_t index) = 0;

	virtual std::string GetTitle()const = 0;
	virtual void SetTitle(const std::string & title) = 0;

	virtual bool CanUndo()const = 0;
	virtual void Undo() = 0;

	virtual bool CanRedo()const = 0;
	virtual void Redo() = 0;

	virtual void Save(const std::string& path)const = 0;

	virtual ~IDocument() = default;
};
