#pragma once
#include <vector>
#include "DocumentItem.h"
#include "Document.h"

class CDocumentItemCollection
{
public:
	bool AddItem(CDocumentItemPtr item, boost::optional<size_t> position);
	bool RemoveItem(size_t position);

	boost::optional<CDocumentItemPtr> GetItem(size_t index) const;
	size_t GetSize() const;

private:
	std::vector<CDocumentItemPtr> m_items;
};

