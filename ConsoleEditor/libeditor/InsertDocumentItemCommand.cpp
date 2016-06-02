#include "stdafx.h"
#include "InsertDocumentItemCommand.h"


CInsertDocumentItemCommand::CInsertDocumentItemCommand(CDocumentItemCollection & collection, CDocumentItemPtr item, boost::optional<size_t> position)
	:m_collection(collection), m_item(item), m_position(position)
{
}

void CInsertDocumentItemCommand::DoExecute()
{
	m_collection.AddItem(m_item, m_position);
}

void CInsertDocumentItemCommand::DoUnexecute()
{
	size_t position = m_position ? m_position.get() : m_collection.GetSize() - 1;
	m_collection.RemoveItem(position);
}
