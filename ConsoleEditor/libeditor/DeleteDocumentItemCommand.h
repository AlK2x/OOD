#pragma once
#include "AbstractCommand.h"
#include "DocumentItemCollection.h"

class CDeleteDocumentItemCommand : public CAbstractCommand
{
public:
	CDeleteDocumentItemCommand(CDocumentItemCollection & collection, CDocumentItemPtr item, size_t position);

protected:
	void DoExecute() override;
	void DoUnexecute() override;

private:
	CDocumentItemCollection & m_collection;
	CDocumentItemPtr m_item;
	size_t m_position;
};

