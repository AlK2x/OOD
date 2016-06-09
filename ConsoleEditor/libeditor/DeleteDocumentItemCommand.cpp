#include "stdafx.h"
#include "DeleteDocumentItemCommand.h"


CDeleteDocumentItemCommand::CDeleteDocumentItemCommand(CDocumentItemCollection & collection, CDocumentItemPtr item, size_t position)
	:m_collection(collection), m_item(item), m_position(position)
{
}

void CDeleteDocumentItemCommand::DoExecute()
{
	m_collection.RemoveItem(m_position);
}

void CDeleteDocumentItemCommand::DoUnexecute()
{
	m_collection.AddItem(m_item, m_position);
}
