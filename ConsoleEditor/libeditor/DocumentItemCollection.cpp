#include "stdafx.h"
#include "DocumentItemCollection.h"

bool CDocumentItemCollection::AddItem(CDocumentItemPtr item, boost::optional<size_t> position)
{
	bool result = true;
	if (position)
	{
		size_t pos = position.get();
		if (pos > m_items.size())
		{
			result = false;
		}
		else
		{
			m_items.emplace(m_items.begin() + pos, item);
		}
	}
	else
	{
		m_items.emplace_back(item);
	}
	return result;
}

bool CDocumentItemCollection::RemoveItem(size_t position)
{
	if (position >= m_items.size())
	{
		return false;
	}
	m_items.erase(m_items.begin() + position);
	return true;
}

boost::optional<CDocumentItemPtr> CDocumentItemCollection::GetItem(size_t index) const
{
	try
	{
		return m_items.at(index);
	}
	catch (std::out_of_range)
	{
		return boost::none;
	}
}

size_t CDocumentItemCollection::GetSize() const
{
	return m_items.size();
}

