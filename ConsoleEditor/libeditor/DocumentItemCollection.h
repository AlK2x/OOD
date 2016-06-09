#pragma once
#include <vector>
#include <boost\optional.hpp>
#include "DocumentItem.h"
//#include "Document.h"

class CDocumentItemCollection
{
public:
	CDocumentItemCollection() {}
	~CDocumentItemCollection() = default;

	bool AddItem(CDocumentItemPtr item, boost::optional<size_t> position);
	bool RemoveItem(size_t position);

	CDocumentItemPtr GetItem(size_t index) const;
	size_t GetSize() const;

private:
	std::vector<CDocumentItemPtr> m_items;
};

