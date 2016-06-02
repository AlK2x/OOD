#pragma once
#include "IParagraph.h"
class CParagraph : public IParagraph
{
public:
	std::string GetText() const override;
	void SetText(const std::string & text) override;

	 ~CParagraph() = default;

private:
	std::string m_text;
};

