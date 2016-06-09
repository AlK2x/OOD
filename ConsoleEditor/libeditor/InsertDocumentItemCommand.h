#pragma once
#include "AbstractCommand.h"
#include "DocumentItemCollection.h"

class CInsertDocumentItemCommand :
	public CAbstractCommand
{
public:
	CInsertDocumentItemCommand(CDocumentItemCollection & collection, CDocumentItemPtr item, boost::optional<size_t> position);

protected:
	virtual void DoExecute() override;
	virtual void DoUnexecute() override;

private:
	CDocumentItemCollection & m_collection;
	CDocumentItemPtr m_item;
	boost::optional<size_t> m_position;
};

