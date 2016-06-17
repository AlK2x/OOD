#pragma once
#include "IParagraph.h"
#include "History.h"
#include "ChangeStringCommand.h"

class CParagraph : public IParagraph
{
public:
	CParagraph(CHistory & history, const std::string & text);

	std::string GetText() const override;
	void SetText(const std::string & text) override;
private:
	std::string m_text;
	CHistory & m_history;
};

