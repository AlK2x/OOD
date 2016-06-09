#include "stdafx.h"
#include "InsertDocumentItemCommand.h"


CInsertDocumentItemCommand::CInsertDocumentItemCommand(CDocumentItemCollection & collection, CDocumentItemPtr item, boost::optional<size_t> position)
	:m_collection(collection), m_item(item), m_position(position)
{
}

void CInsertDocumentItemCommand::DoExecute()
{
	bool result = m_collection.AddItem(m_item, m_position);
	if (!result)
	{
		throw std::out_of_range("Item does not exist. Position: " + std::to_string(m_position.get()));
	}
}

void CInsertDocumentItemCommand::DoUnexecute()
{
	size_t position = m_position ? m_position.get() : m_collection.GetSize() - 1;
	m_collection.RemoveItem(position);
}
